/* Sweeping servo motor */

#include <Servo.h>

const uint8_t SERVO_PIN = 10;

Servo s;            // create servo objet;
int pos = 0;        // position

void setup() {
    s.attach(SERVO_PIN);        // attach servo object to SERVO_PIN
}

void loop() {
    for (pos = 5; pos <= 155; pos += 1) {
        s.write(pos);
        delay(10);   
    }
    for (pos = 155; pos >= 6; pos -= 1) {
        s.write(pos);
        delay(10);
    }    
}
