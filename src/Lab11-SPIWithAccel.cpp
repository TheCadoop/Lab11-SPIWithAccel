/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/cademissner/Desktop/IoT/Lab11-SPIWithAccel/src/Lab11-SPIWithAccel.ino"
void setup();
void loop();
#line 1 "/Users/cademissner/Desktop/IoT/Lab11-SPIWithAccel/src/Lab11-SPIWithAccel.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
#include "LIS3DH.h"

OledWingAdafruit display;
LIS3DHSPI accel(SPI, D3, WKP);

void setup() {
  display.setup();

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();

  LIS3DHConfig config;
	config.setAccelMode(LIS3DH::RATE_100_HZ);
  accel.setup(config);
}

void loop() {
  display.loop();

  LIS3DHSample sample;
  accel.getSample(sample);

  display.clearDisplay();
  display.setTextSize(1.5);
  display.setCursor(0, 0);
  display.printlnf("%d, %d,", sample.x, sample.y);
  display.println(sample.z);
  display.display();

  delay(20);
}