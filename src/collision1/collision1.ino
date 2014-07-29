/* collision detectors as buttons */

const uint8_t LED_PIN = 13;
const uint8_t COLL_RIGHT_PIN = 2;    // Right collision detector PIN
const uint8_t COLL_LEFT_PIN = 3;   // Left collision detector PIN
boolean collision = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(COLL_LEFT_PIN, INPUT);
    pinMode(COLL_RIGHT_PIN, INPUT);
}

void loop() {
    collision = ((digitalRead(COLL_LEFT_PIN) & digitalRead(COLL_RIGHT_PIN)) == LOW);
    if (collision) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}
