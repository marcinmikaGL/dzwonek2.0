#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int buzzerPin = 16;

int melody[] = {
  NOTE_G4, NOTE_C5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_G4, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, 
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_G4, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_A4, NOTE_A4,
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

int noteDurations[] = {
  8, 4, 6, 16, 4, 8, 8, 
  4, 6, 16, 4, 8, 8, 
  4, 8, 8, 4, 8, 8, 4, 8, 8, 2,
  4, 6, 16, 4, 8, 8, 
  4, 6, 16, 4, 8, 8, 
  4, 6, 16, 4, 6, 16, 
  4, 6, 16, 8, 8, 8, 8, 
  2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
  2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
  4, 6, 16, 4, 6, 16, 4, 8, 8, 2,
  2, 8, 8, 8, 8, 3, 8, 2,
  2, 8, 8, 8, 8, 3, 8, 2,
  4, 6, 16, 4, 4, 2, 4, 4, 1
};
int pins[9] = {
5, 4, 2, 14, 12, 13, 15, 3,1
};
const int c = 16;
const char* dzwonik[c]  = {"8:00","8:45","8:55","9:40","9:50","10:35","10:45","11:30","11:50","12:35","12:55","13:40","13:50","14:35","14:40","15:25"};

const char ssid[] = "Miki"; 
const char pass[] = "nuty1234";

// NTP Servers:
static const char ntpServerName[] = "pool.ntp.org";

const int standardTimeZone = 1;
const int daylightTimeZone = 2;

WiFiUDP Udp;
unsigned int localPort = 8888;

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);
bool isDST(time_t t);
int compareTimes(const char* time1, const char* time2);

void setup()
{
  Serial.begin(9600);
  while (!Serial) ;
  delay(250);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  for (int i = 0; i <= 8; i++)
  {
    pinMode(pins[i], OUTPUT);
  }

  while (WiFi.status() != WL_CONNECTED) {
    for (int i = 0; i <= 8; i++){
      digitalWrite(pins[i], HIGH); 
      delay(80);
      digitalWrite(pins[i], LOW); 
      delay(80);
    }
  }
  

  Serial.print("IP number assigned by DHCP is ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  setSyncInterval(300);
}

time_t prevDisplay = 0; 
bool isLesson = false;
int lessonNumber = 0;
void loop()
{
  if (timeStatus() != timeNotSet) {
    if (now() != prevDisplay) {
      prevDisplay = now();
      digitalClockDisplay();
    }
  }
}

void clearDiody() {
  for (int i = 0; i < 9; i++) {
    digitalWrite(pins[i], LOW);
  }
}
void playMelody() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
  }
}

void digitalClockDisplay()
{
  int currentHour = hour();
  int currentMinute = minute();
  char currentTime[6];
  snprintf(currentTime, sizeof(currentTime), "%02d:%02d", currentHour, currentMinute);



  for (int i = 0; i < c - 1; i += 2) {
    if (compareTimes(currentTime, dzwonik[i]) >= 0 && compareTimes(currentTime, dzwonik[i + 1]) < 0) { 
      isLesson = true;
      lessonNumber = i / 2 + 1;
      Serial.print("Lekcja:");
      Serial.println(lessonNumber); 
      int minutesToLessonEnd = minutesToDesignatedTime(dzwonik[((lessonNumber*2)-1)], currentTime);
      Serial.print("dzwonek za: "); 
      Serial.println(minutesToLessonEnd);
      Serial.print("Czas trwania lekcji: ");
      Serial.println(45 - minutesToLessonEnd);
      // int lessonDuration = compareTimes(dzwonik[i + 1], dzwonik[i]); // czas trwania lekcji
      if (minutesToLessonEnd < 5) {
        digitalWrite(pins[0], HIGH);
      } 
      if(minutesToLessonEnd < 10) {
        digitalWrite(pins[1], HIGH);
      } 
      if (minutesToLessonEnd < 15) {
        digitalWrite(pins[2], HIGH);
      } 
      if (minutesToLessonEnd < 20) {
        digitalWrite(pins[3], HIGH);
      } 
      if (minutesToLessonEnd < 25) {
        digitalWrite(pins[4], HIGH);
      } 
      if (minutesToLessonEnd < 30) {
        digitalWrite(pins[5], HIGH);
      } 
      if (minutesToLessonEnd < 35) {
        digitalWrite(pins[6], HIGH);
      } 
      if (minutesToLessonEnd < 40) {
        digitalWrite(pins[7], HIGH);
      } 
      if (minutesToLessonEnd < 44) {
        digitalWrite(pins[8], HIGH);
      } 
      if (minutesToLessonEnd == 45) {
        digitalWrite(pins[9], HIGH);
      }

    } else if (compareTimes(currentTime, dzwonik[i + 1]) >= 0 && compareTimes(currentTime, dzwonik[i + 2]) < 0) {
      if(isLesson == false) {
        digitalWrite(0, HIGH);
        digitalWrite(9, HIGH);
        delay(1000);
      }

      Serial.println("Przerwa");
      playMelody();
      isLesson = false;
      lessonNumber = 0;
      clearDiody();
      break;
    }
  }

  Serial.print(currentHour);
  printDigits(currentMinute);
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(".");
  Serial.print(month());
  Serial.print(".");
  Serial.print(year());
  Serial.print(" Lesson: ");
  Serial.println(lessonNumber);
}




void printDigits(int digits)
{
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

const int NTP_PACKET_SIZE = 48; 
byte packetBuffer[NTP_PACKET_SIZE]; 

time_t getNtpTime()
{
  IPAddress ntpServerIP;

  while (Udp.parsePacket() > 0) ; 
  Serial.println("Transmit NTP Request");

  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);
      unsigned long secsSince1900;
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      time_t timeNow = secsSince1900 - 2208988800UL;
      return timeNow + (isDST(timeNow) ? daylightTimeZone : standardTimeZone) * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0; 
}


void sendNTPpacket(IPAddress &address)
{

  memset(packetBuffer, 0, NTP_PACKET_SIZE);

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

bool isDST(time_t t) {
  tmElements_t tm;
  breakTime(t, tm);

  if (tm.Month < 3 || tm.Month > 10) return false;
  if (tm.Month > 3 && tm.Month < 10) return true;  

  int previousSunday = tm.Day - tm.Wday;
  if (tm.Month == 3) return previousSunday >= 25;
  if (tm.Month == 10) return previousSunday < 25; 

  return false;
}

int compareTimes(const char* time1, const char* time2) {
  int hour1, minute1, hour2, minute2;
  sscanf(time1, "%d:%d", &hour1, &minute1);
  sscanf(time2, "%d:%d", &hour2, &minute2);
  
  if (hour1 < hour2) return -1;
  if (hour1 > hour2) return 1;
  if (minute1 < minute2) return -1;
  if (minute1 > minute2) return 1;
  return 0;
}


int minutesToDesignatedTime(const char* designatedTime, const char* currentTime) {
  int designatedHour, designatedMinute, currentHour, currentMinute;
  sscanf(designatedTime, "%d:%d", &designatedHour, &designatedMinute);
  sscanf(currentTime, "%d:%d", &currentHour, &currentMinute);

  int designatedTotalMinutes = designatedHour * 60 + designatedMinute;
  int currentTotalMinutes = currentHour * 60 + currentMinute;

  int minutesDifference = designatedTotalMinutes - currentTotalMinutes;
  if (minutesDifference < 0) {
    // Jeśli różnica jest ujemna, oznacza to, że wyznaczony czas jest w przeszłości.
    // Aby uzyskać poprawną różnicę czasu, dodajemy 24 godziny (1440 minut).
    minutesDifference += 1440;
  }

  return minutesDifference;
}
