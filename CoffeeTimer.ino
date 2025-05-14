#include <Adafruit_NeoPixel.h>

#define PIN 9 // set attached pin here
#define NUMPIXELS 12 // set number of neopixels here
#define BRIGHTNESS 8 // set brightness here

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned long lastPolled = 0;
unsigned long now = 0;
unsigned long elapsed = 0;
long seconds = 0;
long minutes = 0;
int redLEDNum = NUMPIXELS;
int periods = 0;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pixels.clear();
  for(int i = 0; i < redLEDNum; i++) {
    pixels.setPixelColor(i, pixels.Color(255,0,0));
  }
  pixels.show();
}

void loop() {
  now = millis();
  if (now - lastPolled > 5000) {
    elapsed += (now - lastPolled);
    lastPolled = now;
    int temp = periods;
    seconds = elapsed / 1000; // convert to seconds
    minutes = seconds / 60; // convert to minutes
    periods = minutes / 5; // find number of 5 minute periods

    if(periods != temp) { // only if the period has changed, change the lights
      drawLights();
    }
  }

  if(periods >= NUMPIXELS){
    flash();
  }
}

void drawLights() {
  redLEDNum--;
 
  int j = 0; 
  for(int i = 0; i < redLEDNum; i++) {
    pixels.setPixelColor(i, pixels.Color(255,0,0));
    pixels.show();
    j++;
  }

  for(int i = j; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    pixels.show();
  }

}

void flash() {
  while(true) {
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    for(int i = 0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,255,0));
    }
    pixels.show();
  }
}
