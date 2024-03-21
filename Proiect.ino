#include <Adafruit_NeoPixel.h>

//#define SENSOR_PIN A0
#define NEOPIXEL_PIN 7
//#define RELAY_PIN 8  
#define NUM_LEDS 12

int sensor_pin = A0;       
int relay_pin = 8;         

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  strip.begin();
  strip.show(); 
}

void loop() {
  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor: ");
  Serial.print(sensor_data);
  Serial.print("\t ");

  if (sensor_data > 950) {
    Serial.println("Pamantul e uscat.");
    digitalWrite(relay_pin, LOW);
    setColor(strip.Color(255, 0, 0));  // Red
  } else if (sensor_data >= 700 && sensor_data <= 950) {
    Serial.println("Pamantul e inca umed.");
    digitalWrite(relay_pin, HIGH);
    setColor(strip.Color(0, 255, 0));  // Green
  } else if (sensor_data < 700) {
    Serial.println("Pamantul are apa.");
    digitalWrite(relay_pin, HIGH);
    setColor(strip.Color(0, 0, 255));  // Blue
  }

  delay(100);
}
void setColor(uint32_t color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

  
