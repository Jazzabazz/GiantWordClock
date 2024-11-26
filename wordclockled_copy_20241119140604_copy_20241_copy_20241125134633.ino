#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 100
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50


int hours;    //hours
int minutes;  //mins
int z;

int hourWords[13][2] = {
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
  { 70, 76 },  // twelve
  { 34, 37 }  // one
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
  { 25, 29 }  // five
};

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
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


  z = 12;
  minutes = 45;
  int counter = minutes / 5;
  for (int y = minuteWords[counter][0]; y < minuteWords[counter][1]; y++) {
    pixels.setPixelColor(y, pixels.Color(50, 0, 50));
    if (counter > 6) {
      pixels.setPixelColor(32, pixels.Color(50, 0, 50));
      pixels.setPixelColor(33, pixels.Color(50, 0, 50));
      hours = z;
      hours = hours + 1;
      for (int x = hourWords[hours - 1][0]; x < hourWords[hours - 1][1]; x++) {
        pixels.setPixelColor(x, pixels.Color(50, 0, 50));
      }
    } else {
      pixels.setPixelColor(29, pixels.Color(50, 0, 50));
      pixels.setPixelColor(30, pixels.Color(50, 0, 50));
      pixels.setPixelColor(31, pixels.Color(50, 0, 50));
      pixels.setPixelColor(32, pixels.Color(50, 0, 50));
      hours = z;
      for (int x = hourWords[hours - 1][0]; x < hourWords[hours - 1][1]; x++) {
        pixels.setPixelColor(x, pixels.Color(50, 0, 50));
      }
    }
  }
  pixels.show();
}
