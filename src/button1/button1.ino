/* Blink led with button */

const uint8_t LED_PIN = 13;
const uint8_t BUTTON_PIN = 12;
uint8_t button_state = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    button_state = digitalRead(BUTTON_PIN);
    if (button_state == LOW) {      // Button is in LOW state if it is pushed
        digitalWrite(LED_PIN, HIGH);    
    } else {
        digitalWrite(LED_PIN, LOW);    
    }
}
