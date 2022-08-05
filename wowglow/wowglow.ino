#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    120

CRGB leds[NUM_LEDS];

//MPU vars
Adafruit_MPU6050 mpu;

sensors_event_t a, g, temp; 
float xrot, xangle = 0;
int b;
  
void setup() {
  Serial.begin(9600);
  
  //initialize LEDs
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
  //set all LEDs to blue
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 255);
  }

  ////////////////////

  //initialize MPU
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

}

void loop() {
  int deltime = 10;
  
  // put your main code here, to run repeatedly:
  mpu.getEvent(&a, &g, &temp);

  xrot = g.gyro.x;
  xangle += xrot * ((float)deltime / 1000.0);
  
  Serial.println(xrot);
  Serial.println(xangle);
  Serial.println();
  
  b = (int)(abs(xangle)/90 * 255);
  
  FastLED.setBrightness(b);
  FastLED.show();

  delay(deltime);
}
