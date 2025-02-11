#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "RTClib.h"
#define PIN 4
#define NUMPIXELS 100
#define DELAYVAL 50
RTC_PCF8523 rtc;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int hours;    //hours
int minutes;  //mins
int z;

int hourWords[12][2] = {
  { 34, 37 },  // one
  { 37, 40 },  // two
  { 40, 45 },  // three
  { 45, 49 },  // four
  { 49, 53 },  // five
  { 53, 56 },  // six
  { 56, 61 },  // seven
  { 61, 66 },  // eight
  { 66, 70 },  // nine
  { 81, 84 },  // ten
  { 75, 81 },  // eleven
  { 70, 76 }   // twelve
};

int minuteWords[12][2] = {
  { 0, 0 },    // zero
  { 25, 29 },  // five
  { 16, 19 },  // ten (in minutes)
  { 8, 16 },   // a quarter
  { 19, 25 },  // twenty
  { 19, 29 },  // twenty five
  { 4, 8 },    // half
  { 19, 29 },  // twenty five
  { 19, 25 },  // twenty
  { 8, 16 },   // a quarter
  { 16, 19 },  // ten (in minutes)
  { 25, 29 }   // five
};

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial)
    ;  // wait for serial port to connect. Needed for native USB
#endif

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (!rtc.initialized() || rtc.lostPower()) {
    Serial.println("RTC is NOT initialized, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  rtc.start();
  float drift = 43;                                      // seconds plus or minus over oservation period - set to 0 to cancel previous calibration.
  float period_sec = (7 * 86400);                        // total obsevation period in seconds (86400 = seconds in 1 day:  7 days = (7 * 86400) seconds )
  float deviation_ppm = (drift / period_sec * 1000000);  //  deviation in parts per million (μs)
  float drift_unit = 4.34;                               // use with offset mode PCF8523_TwoHours
  int offset = round(deviation_ppm / drift_unit);
  Serial.print("Offset is ");
  Serial.println(offset);  // Print to control offset
}

void loop() {
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();


  Serial.println();
  delay(3000);

  pixels.clear();
  // IT IS (below)
  pixels.setPixelColor(0, pixels.Color(50, 0, 50));
  pixels.setPixelColor(1, pixels.Color(50, 0, 50));
  pixels.setPixelColor(2, pixels.Color(50, 0, 50));
  pixels.setPixelColor(3, pixels.Color(50, 0, 50));
  //O'CLOCK (below)
  pixels.setPixelColor(84, pixels.Color(50, 0, 50));
  pixels.setPixelColor(85, pixels.Color(50, 0, 50));
  pixels.setPixelColor(86, pixels.Color(50, 0, 50));
  pixels.setPixelColor(87, pixels.Color(50, 0, 50));
  pixels.setPixelColor(88, pixels.Color(50, 0, 50));
  pixels.setPixelColor(89, pixels.Color(50, 0, 50));
  pixels.show();

  z = now.hour();
  minutes = now.minute();
  int counter = 56 / 5;
  for (int y = minuteWords[counter][0]; y < minuteWords[counter][1]; y++) {
    pixels.setPixelColor(y, pixels.Color(50, 0, 50));
    if (counter > 6) {
      Serial.println("above 6");
      pixels.setPixelColor(32, pixels.Color(50, 0, 50));
      pixels.setPixelColor(33, pixels.Color(50, 0, 50));
    } else {
      Serial.println("below 6");
      Serial.println(counter);
      pixels.setPixelColor(29, pixels.Color(50, 0, 50));
      pixels.setPixelColor(30, pixels.Color(50, 0, 50));
      pixels.setPixelColor(31, pixels.Color(50, 0, 50));
      pixels.setPixelColor(32, pixels.Color(50, 0, 50));
    }
  }

  z = 2;
  if (z > 12) z = z - 12;
  Serial.println(z);
  Serial.println(counter);
  hours = z;
  for (int x = hourWords[hours - 1][0]; x < hourWords[hours - 1][1]; x++) {
    if (counter > 6) hours = z + 1;
      pixels.setPixelColor(x, pixels.Color(50, 0, 50));
    }

  Serial.println(hours);
  pixels.show();
}
