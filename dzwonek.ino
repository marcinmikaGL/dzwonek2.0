#include <WiFi.h>
#include "time.h"

const char* ssid     = "Miki";
const char* password = "nuty1234";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
const int c = 16; 
int comparison;
const char* dzwonik[c]  = {"8:00","8:45","8:55","9:40","9:50","10:35","10:45","11:30","11:50","12:35","12:55","13:40","13:50","14:35","14:40","15:25"};

void setup(){
  Serial.begin(9600);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(){
  delay(1000);
   for(int i =0; i<= c; i++) {
    Serial.print("local:");
    Serial.println(LocalTime());
    Serial.print("dzwoniki:");
    Serial.println(dzwonik[i]);
  } 
  
}

char* LocalTime(){
  struct tm timeinfo;
 
  if (!getLocalTime(&timeinfo)) {

    return "0";
  }
  char timeString[6] = {};
  strftime(timeString, 6, "%H:%M", &timeinfo);

   return timeString;
}
