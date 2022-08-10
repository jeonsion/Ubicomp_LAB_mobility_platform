
//모터 드라이버 1 사용
//바퀴 1 핀설정
#define ENA1 7
#define IN1_1 A8
#define IN1_2 A9

//바퀴 2 핀설정
#define IN1_3 A10 
#define IN1_4 A11
#define ENB1 12

//모터드라이버 2 사용 
//바퀴 3 핀설정
#define ENA2 2
#define IN2_1 A2
#define IN2_2 A3

//바퀴 4 핀설정
#define IN2_3 A4
#define IN2_4 A5
#define ENB2 6

#define HC06 Serial3

//#define MOTOR_SPEED 0

//button1,2 => 왼쪽 바퀴
//button3,4 => 오른쪽 바
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

    //매개변수로 바퀴의 전진 후진 방향 설정 
    rc_ctrl_val(bt_cmd);    
  }

  //바퀴가 돌아가는 부분 
  motor_drive();
}


void rc_ctrl_val(unsigned char cmd){
  
  // 정지
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
  
  //앞으로 전진
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

  //뒤로 후진 
  
  if (cmd == '4')
  {
    button1_1 = 0;
    button1_2 = 1;
    button1_3 = 0;
    button1_4 = 0; 
    
    
    button2_1 = 0;
    button2_2 = 1;
    button2_3 = 0;
    button2_4 = 1;
  }

  //왼쪽으로 평행이동   
  if( cmd == '3')
  {
    button1_1 = 0;
    button1_2 = 1;
    button1_3 = 1;
    button1_4 = 0; 
    
    
    button2_1 = 1;
    button2_2 = 0;
    button2_3 = 0;
    button2_4 = 1;
  }
  //오른쪽으로 평행이동 
  if (cmd == '2')
  {
    button1_1 = 1;
    button1_2 = 0;
    button1_3 = 0;
    button1_4 = 1; 
    
    
    button2_1 = 0;
    button2_2 = 1;
    button2_3 = 1;
    button2_4 = 0; 
  }
  //시계방향 회전 
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
  //반시계방향 회전 
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
