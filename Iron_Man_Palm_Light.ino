#include <Adafruit_NeoPixel.h>

#define LED_PIN 6       // NeoPixel ring data pin
#define NUM_LEDS 12     // Number of LEDs
#define FLEX_SENSOR A0  // Flex sensor on A0

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); // Start Serial Monitor
  strip.begin();      // Initialize NeoPixel strip
  strip.clear();      // Turn off all LEDs initially
  strip.show();
  pinMode(FLEX_SENSOR, INPUT);
}

void loop() {
  int flexValue = analogRead(FLEX_SENSOR);  // Read flex sensor
  Serial.print("Flex Sensor Value: ");
  Serial.println(flexValue);  // Print for debugging

  if (flexValue < 1000) {  // If not bent
    setColor(0, 225, 0);  // green
  } else if (flexValue > 1000) {  // Medium bend
    setColor(225, 0, 0);  // red
  } else {
    setColor(0, 0, 255);  // Blue (default state)
  }

  delay(100);  // Small delay
}

void setColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}
