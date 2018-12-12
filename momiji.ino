#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define FANS 10
#define PIXELS_PER_FAN 2

#define RGB_PIN 3
#define RGB_SIZE (FANS * PIXELS_PER_FAN)

#define GRB_PIN 4
#define GRB_SIZE 9

#define UV_RES_PIN 5

uint32_t amethyst = Adafruit_NeoPixel::Color(153, 102, 204); //RGB
uint32_t white = Adafruit_NeoPixel::Color(255, 255, 255); //RGB
Adafruit_NeoPixel RGBPixels = Adafruit_NeoPixel(RGB_SIZE, RGB_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel GRBPixels = Adafruit_NeoPixel(GRB_SIZE, GRB_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  RGBPixels.begin();
  RGBPixels.show();
  
  GRBPixels.begin();
  GRBPixels.show();

  digitalWrite(UV_RES_PIN, LOW);
  pinMode(UV_RES_PIN, OUTPUT);
}

void loop() {
  RGBPixels.fill(amethyst);
  RGBPixels.show();
  
  GRBPixels.fill(amethyst);
  GRBPixels.show();
  
  digitalWrite(UV_RES_PIN, HIGH);
  
  delay(1000);
}
