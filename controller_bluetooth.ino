#define ENA 6
#define IN1 A7
#define IN2 A8
#define HC06 Serial3
#define MOTOR_SPEED 150



boolean button = 0; 
// right motor pins
//#define IN3 A9
//#define IN4 10
//#define ENB 11   

void setup() {
  // set up serial port
  Serial.begin(9600);
  HC06.begin(9600);
  
  // set all the motor pins OUTPUT mode
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
//  pinMode(ENB, OUTPUT);
//  pinMode(IN3, OUTPUT);
//  pinMode(IN4, OUTPUT);


}


void loop() {
  // nothing to do here
   unsigned char bt_cmd = 0;
   
   if(HC06.available()){      //controller to uno 
    bt_cmd = HC06.read();
    rc_ctrl_val(bt_cmd);    
  }
  motor_drive();
}


void rc_ctrl_val(unsigned char cmd){
  if (cmd == '1')
  {
    button = 1;
  }
  else{
        button = 0;

  }
}



void motor_drive(){
    
    digitalWrite(IN1, button);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, HIGH);
}

