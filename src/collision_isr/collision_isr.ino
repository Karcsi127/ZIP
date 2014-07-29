/* collision detectors as buttons */

const uint8_t LED_PIN = 13;
const uint8_t COLL_RIGHT_PIN = 2;    // Right collision detector PIN
const uint8_t COLL_RIGHT_ISR = 0;   // interrupt ID for PIN 2
const uint8_t COLL_LEFT_PIN = 3;   // Left collision detector PIN
const uint8_t COLL_LEFT_ISR = 1;   // interrupt ID for PIN 3
volatile int led_state = LOW;  

void blink() {
    led_state = !led_state;   
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(COLL_LEFT_PIN, INPUT);
    pinMode(COLL_RIGHT_PIN, INPUT);
    attachInterrupt(COLL_RIGHT_ISR, blink, FALLING);
    attachInterrupt(COLL_LEFT_ISR, blink, FALLING);
}

void loop() {
    digitalWrite(LED_PIN, led_state);
    delay(100);
}
