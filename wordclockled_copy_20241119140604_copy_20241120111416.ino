#include <Adafruit_NeoPixel.h>
#define PIN 4
#define NUMPIXELS 100
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50


int hours;    //hours
int minutes;  //mins

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
  { 70, 76 },  // twelve
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
  { 25, 29 },  // five
};

/*{ 29, 33 },  // past
  { 32, 34 },  // to*/

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


  hours = 1;
  minutes = 48;
  int counter = minutes / 5;
  for (int y = minuteWords[counter][0]; y < minuteWords[counter][1]; y++) {
    pixels.setPixelColor(y, pixels.Color(50, 0, 50));
    if (counter > 6) hours = hours + 1;
  }
  pixels.show();

  for (int x = hourWords[hours - 1][0]; x < hourWords[hours - 1][1]; x++) {
    pixels.setPixelColor(x, pixels.Color(50, 0, 50));
  }
  pixels.show();


  /*
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
  }*/
}
