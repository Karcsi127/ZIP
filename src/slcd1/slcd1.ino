/* Simple counter for LCD */
#include <SerialLCD.h>
#include <SoftwareSerial.h>

const uint8_t LCD_RX_PIN = 8;
const uint8_t LCD_TX_PIN = 13;   // collide with LED

// initialize the library
SerialLCD slcd(LCD_RX_PIN, LCD_TX_PIN);

void setup() {
  slcd.begin();
  slcd.print("Hello, world!");
}

void loop() {
  slcd.setCursor(0, 1);
  // print the number of seconds since reset:
  slcd.print(millis()/1000,DEC);
}
