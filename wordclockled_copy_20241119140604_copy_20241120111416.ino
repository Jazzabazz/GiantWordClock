#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 100
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50


int h;  //hours
int m;  //mins

int clockWords[24][2] = {
  { 0, 1 },    // it
  { 2, 3 },    // is
  { 4, 7 },    // half
  { 19, 28 },  // twenty five
  { 19, 24 },  // twenty
  { 9, 15 },   // quarter
  { 16, 18 },  // ten (in minutes)
  { 25, 28 },  // five
  { 29, 32 },  // past
  { 32, 33 },  // to
  { 34, 36 },  // one
  { 37, 39 },  // two
  { 40, 44 },  // three
  { 45, 48 },  // four
  { 49, 52 },  // five
  { 53, 55 },  // six
  { 56, 60 },  // seven
  { 61, 65 },  // eight
  { 66, 69 },  // nine
  { 81, 83 },  // ten
  { 75, 80 },  // eleven
  { 70, 75 },  // twelve
  { 84, 89 }   // o'clock
}

void
setup() {

  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(50, 0, 50));
  pixels.setPixelColor(1, pixels.Color(50, 0, 50));
  pixels.setPixelColor(2, pixels.Color(50, 0, 50));
  pixels.setPixelColor(3, pixels.Color(50, 0, 50));
  pixels.show();

  for (int x = clockWords[h - 1][0]; x < clockWords[h - 1][1], x++) {
    pixels.setPixelColor(x, pixels.Color(50, 0, 50));
  }
  pixels.show();


  h = 1;
  switch (h) {
    case 1:
      for (int i = 34; i < 37; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 2:
      for (int i = 37; i < 40; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 3:
      for (int i = 40; i < 45; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 4:
      for (int i = 45; i < 49; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 5:
      for (int i = 49; i < 53; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 6:
      for (int i = 53; i < 56; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 7:
      for (int i = 56; i < 61; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 8:
      for (int i = 61; i < 66; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 9:
      for (int i = 66; i < 70; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 10:
      for (int i = 81; i < 84; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 11:
      for (int i = 75; i < 81; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 12:
      for (int i = 70; i < 76; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
  }


  m = 0;
  switch (m) {
    case 5:
      for (int i = 25; i < 29; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 10:
      for (int i = 16; i < 19; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 15:
      pixels.setPixelColor(8, pixels.Color(50, 0, 50));  //A
      pixels.show();
      for (int i = 9; i < 16; i++) {  //QUARTER
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {  //PAST
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 20:
      for (int i = 19; i < 25; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {  //PAST
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 25:
      for (int i = 19; i < 29; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {  //PAST
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 30:
      for (int i = 4; i < 8; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 29; i < 33; i++) {  //PAST
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 35:
      for (int i = 19; i < 29; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 32; i < 34; i++) {  //TO
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 40:
      for (int i = 19; i < 25; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 32; i < 34; i++) {  //TO
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 45:
      pixels.setPixelColor(8, pixels.Color(50, 0, 50));  //A
      pixels.show();
      for (int i = 9; i < 16; i++) {  //QUARTER
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 32; i < 34; i++) {  //TO
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 50:
      for (int i = 16; i < 19; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 32; i < 34; i++) {  //TO
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 55:
      for (int i = 25; i < 29; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      for (int i = 32; i < 34; i++) {  //TO
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
    case 0:
      for (int i = 84; i < 90; i++) {
        pixels.setPixelColor(i, pixels.Color(50, 0, 50));
        pixels.show();
      }
      break;
  }
}
