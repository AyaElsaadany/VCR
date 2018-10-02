#include <SoftwareSerial.h>
int motor1_In1=13;  //2
int motor1_In2=12;  //7
int motor2_In1=8;   //10
int motor2_In2=7;   //15
String voice;
int buzzer=5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motor1_In1,OUTPUT);
  pinMode(motor1_In2,OUTPUT);
  pinMode(motor2_In1,OUTPUT);
  pinMode(motor2_In2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()){ 
     delay(10);  
    char c = Serial.read(); 
    if (c == '#'){
      break;
    } 
    voice += c; 
  }
  if (voice.length() > 0){
    if(voice == "*go ahead"){
      forwardCar();
      }
    else if(voice == "*go back"){
      backwardCar();
      }
    else if(voice == "*turn right") {
      rightCar();
    }
    else if(voice == "*turn left") {
      leftCar();
    }
    else if(voice == "*stop") {
      stopCar();
    }
    else if(voice=="*are you ready"){
      turnAround();
      buzzerON();
    }
    else if(voice=="*buzzer"){
      buzzerON();
    }
    
  voice=""; 
  }
}


void forwardCar(){
   digitalWrite(motor1_In2,HIGH);
 digitalWrite(motor1_In1,LOW);
 digitalWrite(motor2_In2,HIGH);
 digitalWrite(motor2_In1,LOW);
 delay(1000);
 stopCar();
}

void backwardCar(){
 digitalWrite(motor1_In1,HIGH);
 digitalWrite(motor1_In2,LOW);
 digitalWrite(motor2_In1,HIGH);
 digitalWrite(motor2_In2,LOW);
  delay(1000);
 stopCar();
}

void rightCar(){
 digitalWrite(motor1_In1,HIGH);
 digitalWrite(motor1_In2,LOW);
 digitalWrite(motor2_In1,LOW);
 digitalWrite(motor2_In2,LOW);
 delay(500);
 forwardCar();
 stopCar();
}

 void leftCar(){
  digitalWrite(motor1_In1,LOW);
  digitalWrite(motor1_In2,LOW);
  digitalWrite(motor2_In1,HIGH);
  digitalWrite(motor2_In2,LOW);
  delay(500);
  forwardCar();
 stopCar();
}

void stopCar(){
  digitalWrite(motor1_In1,LOW);
  digitalWrite(motor1_In2,LOW);
  digitalWrite(motor2_In1,LOW);
  digitalWrite(motor2_In2,LOW);
}

void turnAround(){
   digitalWrite(motor1_In1,HIGH);
 digitalWrite(motor1_In2,LOW);
 digitalWrite(motor2_In1,LOW);
 digitalWrite(motor2_In2,LOW);
 delay(2000);
}

void buzzerON(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  
}


