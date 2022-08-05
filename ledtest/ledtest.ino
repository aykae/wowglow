#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    120

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
  binary();
  //single();
}

void single() {
  //leds[48] = CRGB(0,0,255);
  leds[0] = CRGB(0, 0, 255);
  leds[49] = CRGB(0, 0, 255);
  FastLED.show();
}

void binary() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(40);
  }
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(40);
  }
}
