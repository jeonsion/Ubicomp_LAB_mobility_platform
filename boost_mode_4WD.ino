
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
boolean button1 = 0;
boolean button2 = 0;
boolean button3 = 0;
boolean button4 = 0; 

//for booter mode
int cnt = 0;
boolean Booster = 0;

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

    if(bt_cmd =='B'){
      Booster = 1;
      cnt++;
    }

    //매개변수로 바퀴의 전진 후진 방향 설정 
    rc_ctrl_val(bt_cmd);    
  }
  //바퀴가 돌아가는 부분 
  if(Booster == 0){
    motor_drive();
  }
  else if(Booster == 1){
    B_moter_drive();
  }


}


void rc_ctrl_val(unsigned char cmd){
  
  // 정지
  if(cmd == '0')
  {
    button1 = 0;
    button2 = 0;
    button3 = 0;
    button4 = 0;
  }
  
  //앞으로 전진
  if (cmd == '1')
  {
    button1 = 1;
    button2 = 0;
    button3 = 1;
    button4 = 0;
  }

  //뒤로 후
  
  if (cmd == '4')
  {
    button1 = 0;
    button2 = 1;
    button3 = 0;
    button4 = 1;
  }

  //왼쪽으로 회전 
  if( cmd == '2')
  {
    button1 = 0;
    button2 = 1;
    button3 = 1;
    button4 = 0;
  }

  if (cmd == '3')
  {
    button1 = 1;
    button2 = 0;
    button3 = 0;
    button4 = 1;
    
  }

  if(cnt%2 == 0){
    Booster = 0;
  }else if(cnt % 2 ==1){
    Booster =1;
  }
}


void motor_drive(){
    
    digitalWrite(IN1_1, button1);
    digitalWrite(IN1_2, button2);
    digitalWrite(IN1_3, button1);
    digitalWrite(IN1_4, button2);
    analogWrite(ENA1, 25);
    analogWrite(ENB1, 25);


    digitalWrite(IN2_1, button3);
    digitalWrite(IN2_2, button4);
    digitalWrite(IN2_3, button3);
    digitalWrite(IN2_4, button4);
    analogWrite(ENA2, 25);
    analogWrite(ENB2, 25);
    

    
}
void B_motor_drive(){
    
    digitalWrite(IN1_1, button1);
    digitalWrite(IN1_2, button2);
    digitalWrite(IN1_3, button1);
    digitalWrite(IN1_4, button2);
    analogWrite(ENA1, 255);
    analogWrite(ENB1, 255);


    digitalWrite(IN2_1, button3);
    digitalWrite(IN2_2, button4);
    digitalWrite(IN2_3, button3);
    digitalWrite(IN2_4, button4);
    analogWrite(ENA2, 255);
    analogWrite(ENB2, 255);
    

    
}
