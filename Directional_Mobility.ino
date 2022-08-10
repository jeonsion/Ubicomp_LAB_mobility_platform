
#define ENA1 7
#define IN1_1 A8
#define IN1_2 A9

#define IN1_3 A10 
#define IN1_4 A11
#define ENB1 12

#define ENA2 2
#define IN2_1 A2
#define IN2_2 A3

#define IN2_3 A4
#define IN2_4 A5
#define ENB2 6

#define HC06 Serial3


boolean button1_1 = 0;
boolean button1_2 = 0;
boolean button1_3 = 0;
boolean button1_4 = 0; 


boolean button2_1 = 0;
boolean button2_2 = 0;
boolean button2_3 = 0;
boolean button2_4 = 0; 



void setup() {
  // set up serial port
  Serial.begin(9600);
  HC06.begin(9600);
  
  // set all the motor pins OUTPUT mode
  
  pinMode(ENA1, OUTPUT); 
  pinMode(IN1_1, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN1_3, OUTPUT);
  pinMode(IN1_4, OUTPUT);
  pinMode(ENB2, OUTPUT);

  
  pinMode(ENA2, OUTPUT);
  pinMode(IN2_1, OUTPUT);
  pinMode(IN2_2, OUTPUT);
  pinMode(IN2_3, OUTPUT);
  pinMode(IN2_4, OUTPUT);
  pinMode(ENB2, OUTPUT);


}


void loop() {
  // nothing to do here
   unsigned char bt_cmd = 0;
   
   if(HC06.available()){     //controller to uno 
    bt_cmd = HC06.read();

    rc_ctrl_val(bt_cmd);    
  }

  motor_drive();
}


void rc_ctrl_val(unsigned char cmd){
  
  if(cmd == '0')
  {
    button1_1 = 0;
    button1_2 = 0;
    button1_3 = 0;
    button1_4 = 0; 
    
    
    button2_1 = 0;
    button2_2 = 0;
    button2_3 = 0;
    button2_4 = 0; 
  }
  
  if (cmd == '1')
  {
    button1_1 = 1;
    button1_2 = 0;
    button1_3 = 1;
    button1_4 = 0; 
    
    
    button2_1 = 1;
    button2_2 = 0;
    button2_3 = 1;
    button2_4 = 0;
  }

  if (cmd == '4')
  {
    button1_1 = 0;
    button1_2 = 1;
    button1_3 = 0;
    button1_4 = 1; 
    
    
    button2_1 = 0;
    button2_2 = 1;
    button2_3 = 0;
    button2_4 = 1;
  }

  if( cmd == '2')
  {
    button1_1 = 0;
    button1_2 = 1;
    button1_3 = 1;
    button1_4 = 0; 
    
    
    button2_1 = 0;
    button2_2 = 1;
    button2_3 = 1;
    button2_4 = 0;
  }
  if (cmd == '3')
  {
    button1_1 = 1;
    button1_2 = 0;
    button1_3 = 0;
    button1_4 = 1; 
    
    
    button2_1 = 1;
    button2_2 = 0;
    button2_3 = 0;
    button2_4 = 1; 
  }
  if (cmd == 'f')
  {
    button1_1 = 1;
    button1_2 = 0;
    button1_3 = 1;
    button1_4 = 0; 
    
    
    button2_1 = 0;
    button2_2 = 1;
    button2_3 = 0;
    button2_4 = 1; 
  }
  if(cmd == 'b')
  {
    button1_1 = 0;
    button1_2 = 1;
    button1_3 = 0;
    button1_4 = 1; 
    
    
    button2_1 = 1;
    button2_2 = 0;
    button2_3 = 1;
    button2_4 = 0; 
  }
}


void motor_drive(){
    
    digitalWrite(IN1_1, button1_1);
    digitalWrite(IN1_2, button1_2);
    digitalWrite(IN1_3, button1_3);
    digitalWrite(IN1_4, button1_4);
    analogWrite(ENA1, 100);
    analogWrite(ENB1, 100);


    digitalWrite(IN2_1, button2_1);
    digitalWrite(IN2_2, button2_2);
    digitalWrite(IN2_3, button2_3);
    digitalWrite(IN2_4, button2_4);
    analogWrite(ENA2, 100);
    analogWrite(ENB2, 100);
    

    
}
