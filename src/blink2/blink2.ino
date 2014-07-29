/* Blinking LED on PIN 13
   with constants and variables
*/

const uint8_t LED_PIN = 13;
unsigned long BLINK_DELAY = 1000;

void setup() {
    pinMode(LED_PIN, OUTPUT);        // set LED_PIN to digital OUTPUT mode
}

void loop() {
    digitalWrite(LED_PIN, HIGH);    // write digital HIGH to LED_PIN
    delay(BLINK_DELAY);            // wait for BLINK_DELAY millisec
    digitalWrite(LED_PIN, LOW);    // write digital LOW to LED_PIN
    delay(BLINK_DELAY);            // wait for BLINK_DELAY millisec
}
