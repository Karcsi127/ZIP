const uint8_t LED_PIN = 13;
const uint8_t MOTOR_LEFT_DIR_PIN = 4;
const uint8_t MOTOR_LEFT_SPEED_PIN = 5;
const uint8_t MOTOR_RIGHT_DIR_PIN = 7;
const uint8_t MOTOR_RIGHT_SPEED_PIN = 6;

const uint8_t COLL_RIGHT_PIN = 2;    // Right collision detector PIN
const uint8_t COLL_RIGHT_ISR = 0;   // interrupt ID for PIN 2
const uint8_t COLL_LEFT_PIN = 3;   // Left collision detector PIN
const uint8_t COLL_LEFT_ISR = 1;   // interrupt ID for PIN 3

const uint8_t FORWARD = LOW;
const uint8_t BACKWARD = HIGH;

const uint8_t MAX_SPEED = 250;

volatile bool coll_left = false;
volatile bool coll_right = false;

void motor_set_speed(uint8_t left, uint8_t right) {
    analogWrite(MOTOR_LEFT_SPEED_PIN, left);
    analogWrite(MOTOR_RIGHT_SPEED_PIN, right);
}

void motor_set_direction(uint8_t left, uint8_t right) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, left);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, right);
}

void motor_stop() {
    motor_set_speed(0, 0);
}

void motor_go_forward() {
    motor_set_direction(FORWARD, FORWARD);
    motor_set_speed(MAX_SPEED, MAX_SPEED);
}

void motor_go_backward(unsigned long time) {
    motor_set_direction(BACKWARD, BACKWARD);
    motor_set_speed(MAX_SPEED, MAX_SPEED);
    delay(time);
}

void motor_turn(int degree) {
    if (degree >= 0) {
        motor_set_direction(FORWARD, BACKWARD);
    } else {
        motor_set_direction(BACKWARD, FORWARD);
    }
    motor_set_speed(MAX_SPEED, MAX_SPEED);
    delay(abs(degree)*5);
}


void left_collision_callback() {
    int coll_state = digitalRead(COLL_LEFT_PIN);
    if (coll_state == LOW && coll_left == false) {
        coll_left = true;
    }
}

void right_collision_callback() {
    int coll_state = digitalRead(COLL_RIGHT_PIN);
    if (coll_state == LOW && coll_right == false) {
        coll_right = true;
    }
}

void setup() {
    // inital states
    pinMode(MOTOR_LEFT_DIR_PIN, OUTPUT);
    pinMode(MOTOR_LEFT_SPEED_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_DIR_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_SPEED_PIN, OUTPUT); 

    digitalWrite(MOTOR_LEFT_DIR_PIN, LOW);
    digitalWrite(MOTOR_LEFT_SPEED_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_SPEED_PIN, LOW);
  
    pinMode(LED_PIN, OUTPUT); 
    digitalWrite(LED_PIN, LOW); 
    pinMode(COLL_LEFT_PIN, INPUT);
    
    attachInterrupt(COLL_RIGHT_ISR, right_collision_callback, FALLING);
    attachInterrupt(COLL_LEFT_ISR, left_collision_callback, FALLING);
    
    // start
    motor_go_forward();
}


void handle_collision(int degree) {
    digitalWrite(LED_PIN, HIGH);
    motor_stop();
    motor_go_backward(2000); // 1 sec
    motor_stop();
    motor_turn(degree); 
    motor_stop();
    motor_go_forward();
    digitalWrite(LED_PIN, LOW);  
}

void loop() {
    if (coll_left || coll_right) {
      if (coll_left) {
          handle_collision(90);  // turn left
      } else {
          handle_collision(-90);  // turn right
      }
      coll_left = false;
      coll_right = false;
    }
    delay(100);
}
