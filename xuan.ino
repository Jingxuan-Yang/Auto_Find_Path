//============================智宇科技===========================
//  智能小车指定花式动作
//===============================================================
//#include <Servo.h> 
int Left_motor_go=6;     //左电机前进(IN1)
int Left_motor_back=9;     //左电机后退(IN2)

int Right_motor_go=10;    // 右电机前进(IN3)
int Right_motor_back=11;    // 右电机后退(IN4)

void setup()
{
  //初始化电机驱动IO为输出方式
  pinMode(Left_motor_go,OUTPUT); // PIN 6 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 10 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 11 (PWM)
}

void brake(int time)         //刹车，停车
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);//执行时间，可以调整  
}
void run (int time)     // 前进
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,175);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,LOW);  // 左电机前进
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);//PWM比例0~255调速，左右轮差异略增减
  analogWrite(Left_motor_back,200);
  delay(time * 100);   //执行时间，可以调整  
}
void left(int time)         //左转(左轮不动，右轮前进)
{
  digitalWrite(Right_motor_go,HIGH);  // 右电机前进
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,110); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,LOW);   //左轮后退
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(time * 100);  //执行时间，可以调整  
}

void right(int time)        //右转(右轮不动，左轮前进)
{
  digitalWrite(Right_motor_go,LOW);   //右电机后退
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);//PWM比例0~255调速
  digitalWrite(Left_motor_go,LOW);//左电机前进
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,110);//PWM比例0~255调速
  delay(time * 100);  //执行时间，可以调整  
}

void back(int time)          //后退
{
  digitalWrite(Right_motor_go,LOW);  //右轮后退
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,100);//PWM比例0~255调速
  digitalWrite(Left_motor_go,HIGH);  //左轮后退
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,100);
  analogWrite(Left_motor_back,0);//PWM比例0~255调速
  delay(time * 100);     //执行时间，可以调整  
}

void loop()
{    
  int i;
  delay(2000); //延时2s后启动
  run(1);
  left(5);
  brake(5);
  run(1);
  right(5);
  run(1);
  right(5);
  run(1);
  left(5);
  brake(5);
  run(1);
  left(5);
  brake(5);
  run(1);
  delay(2000);
}

