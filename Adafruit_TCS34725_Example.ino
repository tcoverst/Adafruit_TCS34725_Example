#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found TCS34725 color sensor");
  } else {
    Serial.println("Could not find TCS34725 color sensor");
    while (1); // halt
  }
}

void loop() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  Serial.print("Red: "); Serial.print(r);
  Serial.print(" Green: "); Serial.print(g);
  Serial.print(" Blue: "); Serial.print(b);
  Serial.print(" Clear: "); Serial.println(c);
  delay(500);
}
