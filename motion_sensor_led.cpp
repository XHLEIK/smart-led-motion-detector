// motion_sensor_led.cpp

const int TRIG_PIN = 6;
const int ECHO_PIN = 7;
const int LED_PIN  = 13;
const int DISTANCE_THRESHOLD = 30;  // in cm
const unsigned long LIGHT_DURATION = 5000;  // 5 seconds

float duration_us, distance_cm;
bool lightOn = false;
unsigned long lightStartTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure echo pulse duration
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance (cm)
  distance_cm = duration_us * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // Turn LED on if object detected within threshold
  if (!lightOn && distance_cm > 0 && distance_cm <= DISTANCE_THRESHOLD) {
    Serial.println("Motion detected - LED ON");
    digitalWrite(LED_PIN, HIGH);
    lightStartTime = millis();
    lightOn = true;
  }

  // Turn LED off after LIGHT_DURATION
  if (lightOn && millis() - lightStartTime >= LIGHT_DURATION) {
    Serial.println("Time expired - LED OFF");
    digitalWrite(LED_PIN, LOW);
    lightOn = false;
  }

  delay(200);  // Delay for stability
}
