/* collision detectors  */

const uint8_t COLL_RIGHT_PIN = 2;    // Right collision detector PIN
const uint8_t COLL_LEFT_PIN = 3;   // Left collision detector PIN
uint8_t coll_left = 0;
uint8_t coll_right = 0;

void setup() {
    Serial.begin(9600);            // init serial port with 9600 baud speed
    pinMode(COLL_LEFT_PIN, INPUT);
    pinMode(COLL_RIGHT_PIN, INPUT);
}

void loop() {
     coll_left = digitalRead(COLL_LEFT_PIN) == LOW;
     coll_right = digitalRead(COLL_RIGHT_PIN) == LOW;
     Serial.print(coll_left);
     Serial.print(" ");
     Serial.print(coll_right);
     Serial.print(" ");
     Serial.println((coll_left << 1) | coll_right);
     delay(100);    
}
