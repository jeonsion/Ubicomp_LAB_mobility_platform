//제자리 토네이
// left motor pins
#define ENA 6
#define IN1 A7
#define IN2 A8

// right motor pins
#define IN3 A9
#define IN4 A10
#define ENB 11   

void setup() {
  // set up serial port
  Serial.begin(9600);
  
  // set all the motor pins OUTPUT mode
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

   //wait 2 seconds after power up
  delay(2000);

  // set motors to move forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  for (int pwm = 1; pwm <= 255; pwm+=5) {
    Serial.println(pwm);
    digitalWrite(ENA, pwm);
    digitalWrite(ENB, pwm);
    delay(100);
  }

  // stop motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // nothing to do here
}
