#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
// Подключаем библиотеку FastLED.
#include "FastLED.h"

// Указываем, какое количество пикселей у нашей ленты.
#define LED_COUNT 120 
// Указываем, к какому порту подключен вход ленты DIN.
#define LED_PIN 5
 
// Создаем переменную strip для управления нашей лентой.
CRGB strip[LED_COUNT];

// hfhfhh
int CC = 0;

#ifndef APSSID
#define APSSID "Logic stend"
#define APPSK  "ITMO_2023"
#endif

const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

#define LED 4
int statusLED = HIGH; // Начальный статус светодиода ВЫКЛЮЧЕН. Светодиод инверсный

const String HtmlHtml = "<html><head><meta charset=\"utf-8\">"
"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlTitle = "<h1>ITMO 2023</h1><br/>\n";
const String HtmlTitle2 = "<h1>Стенд базовой логики</h1><br/>\n";
const String HtmlLedStateLow = "<big>Демонстрация<b>Выключена</b></big><br/><br/>\n";
const String HtmlLedStateHigh = "<big>Демонстрация<b>Включена</b></big><br/><br/>\n";
const String HtmlButtons = 
"<a href=\"LEDOff\"><button style=\"background-color:red;color:white;width:20%;height:5%;\">Выключить </button></a>\n"
"<a href=\"LEDOn\"><button style=\"background-color:green;color:white;width:20%;height:5%;\">Включить </button></a><br/>";
const String HtmlHtmlClose = "</html>";

void handleLedOn() {
  statusLED = HIGH; // conditions to make the LED turn on
  //digitalWrite(LED, statusLED);
  //Serial.println("Демонстрация запущена");
  for (int i = 0; i < LED_COUNT; i++)
  {
    strip[i] = CRGB::Blue; // Черный цвет, т.е. выключено.
    FastLED.show();
    delay(10); 
    strip[i] = CRGB::Black; // Черный цвет, т.е. выключено.
    FastLED.show();
  }
  // Передаем цвета ленте.
  //FastLED.show();
  response();

}

void handleLedOff() {
  statusLED = LOW; // conditions to make the LED turn off
  //digitalWrite(LED, statusLED);
  //Serial.println("Демонстрация остановлена");
    for (int i = 0; i < LED_COUNT; i++)
  {
    strip[i] = CRGB::Black;  // Черный цвет, т.е. выключено.
  }
  // Передаем цвета ленте.
  FastLED.show();
  response();
}

void response(){
  String htmlRes = HtmlHtml + HtmlTitle+HtmlTitle2;
  if(statusLED == LOW){
    htmlRes += HtmlLedStateLow;
  }else{
    htmlRes += HtmlLedStateHigh;

    
  }
 
  htmlRes += HtmlButtons;
  htmlRes += HtmlHtmlClose; 
  server.send(200, "text/html", htmlRes);
}
 
void setup() {
    FastLED.addLeds<WS2812B, LED_PIN, RGB>(strip, LED_COUNT);
    //FastLED.clear();
    //delay(1000); 
    //itmo();
    //CC = 0;
    WiFi.softAP(ssid, password); 
    IPAddress apip = WiFi.softAPIP();     
    server.on("/", response); 
    server.on("/LEDOff", handleLedOff);
    server.on("/LEDOn", handleLedOn); 
    server.begin();    
    //pinMode(LED, OUTPUT);
    //digitalWrite(LED, statusLED);
    //Serial.begin(9600);
    //Serial.println("Start");
        
    
}
 
void itmo() {
  if (CC == 0) {

//i
strip[0] = CRGB::Blue; 
strip[2] = CRGB::Blue; 
strip[3] = CRGB::Blue; 
strip[4] = CRGB::Blue; 
strip[5] = CRGB::Blue;
// T
strip[16] = CRGB::Blue; 
strip[32] = CRGB::Blue;
strip[31] = CRGB::Blue; 
strip[30] = CRGB::Blue; 
strip[29] = CRGB::Blue; 
strip[28] = CRGB::Blue;
strip[27] = CRGB::Blue; 
strip[26] = CRGB::Blue; 

//M
strip[42] = CRGB::Blue; 
strip[43] = CRGB::Blue; 
strip[44] = CRGB::Blue; 
strip[45] = CRGB::Blue; 
strip[46] = CRGB::Blue; 
strip[47] = CRGB::Blue;
strip[49] = CRGB::Blue; 
strip[61] = CRGB::Blue; 
strip[65] = CRGB::Blue;
strip[74] = CRGB::Blue; 
strip[75] = CRGB::Blue; 
strip[76] = CRGB::Blue; 
strip[77] = CRGB::Blue; 
strip[78] = CRGB::Blue; 
strip[79] = CRGB::Blue;

//O
strip[91] = CRGB::Blue; 
strip[92] = CRGB::Blue; 
strip[93] = CRGB::Blue; 
strip[94] = CRGB::Blue; 
strip[96] = CRGB::Blue; 
strip[111] = CRGB::Blue;
strip[101] = CRGB::Blue; 
strip[106] = CRGB::Blue; 
strip[113] = CRGB::Blue;
strip[114] = CRGB::Blue; 
strip[115] = CRGB::Blue; 
strip[116] = CRGB::Blue; 

FastLED.show();
//CC = 1;
  }
  
}

void loop() {
    itmo();
    server.handleClient();
    // Включаем все светодиоды
        
}
