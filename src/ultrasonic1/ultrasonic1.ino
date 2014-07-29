const uint8_t ULTRASONIC_PIN = 9;
long duration = 0; 
float cm = 0;

void setup() {
    Serial.begin(9600);
    
}

void loop() {
  pinMode(ULTRASONIC_PIN, OUTPUT);
  digitalWrite(ULTRASONIC_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_PIN, HIGH);
  delayMicroseconds(5);
  
  pinMode(ULTRASONIC_PIN, INPUT);
  duration = pulseIn(ULTRASONIC_PIN, HIGH);
  cm = duration / 57.8;   // v_s = 346 m / s
  
  Serial.print(duration);
  Serial.print(" ");
  Serial.println(cm);
  delay(100);
} 
