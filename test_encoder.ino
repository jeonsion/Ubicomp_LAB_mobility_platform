//엔코더를 사용한 정밀한 위치제어 테스트 코드 (모터 1개 구동)


//motor control pin 
const int motorDirPin = A8;
const int motorPWMPin = 9;

//encoder pin
const int encoderPinA = A2;
const int encoderPinB = A3;
int encoderPos = 0;
const float ratio = 360./103./52.;

// P control
float Kp = 30;
float targetDeg = 360;

void doEncoderA(){  encoderPos += (digitalRead(encoderPinA)==digitalRead(encoderPinB))?1:-1;}
void doEncoderB(){  encoderPos += (digitalRead(encoderPinA)==digitalRead(encoderPinB))?-1:1;}

void doMotor(bool dir, int vel){
  digitalWrite(motorDirPin, dir);
  analogWrite(motorPWMPin, dir?(255 - vel):vel);
}

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE);
 
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(1, doEncoderB, CHANGE);
 
  pinMode(motorDirPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  float motorDeg = float(encoderPos)*ratio;
 
  float error = targetDeg - motorDeg;
  float control = Kp*error;

  doMotor( (control>=0)?HIGH:LOW, min(abs(control), 255));

  Serial.print("encoderPos : ");
  Serial.print(encoderPos);
  Serial.print("   motorDeg : ");
  Serial.print(float(encoderPos)*ratio);
  Serial.print("   error : ");
    Serial.print(error);
  Serial.print("    control : ");
  Serial.print(control);
  Serial.print("    motorVel : ");
  Serial.println(min(abs(control), 255));
}
