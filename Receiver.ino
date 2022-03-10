#include <VirtualWire.h>
#define backled 12
#define rightled 2
#define leftled 4
#define en1 7
#define en2 8

char r=0;
void setup() {
  vw_set_rx_pin(6);
  vw_setup(2000);
  vw_rx_start();
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  pinMode(backled,OUTPUT);
  pinMode(rightled,OUTPUT);
  pinMode(leftled,OUTPUT);
  Serial.begin(9600);
}
void loop() { 
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  if (vw_get_message(buf, &buflen))
    {
  if(buf[0]=='S'){  
  Serial.println("stop");
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(rightled,LOW);
  digitalWrite(leftled,LOW);
  digitalWrite(backled,LOW);
 }  
  else if(buf[0]=='R'){
    Serial.println("Right");
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(rightled,HIGH);
  digitalWrite(leftled,LOW);
  digitalWrite(backled,LOW);
 }
  else if(buf[0]=='L'){
    Serial.println("Left");
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(rightled,LOW);
  digitalWrite(leftled,HIGH);
  digitalWrite(backled,LOW);
 }
  else if(buf[0]=='B'){
    Serial.println("back");
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(rightled,LOW);
  digitalWrite(leftled,LOW);
  digitalWrite(backled,HIGH);
 }
  else if(buf[0]=='F'){
    Serial.println("forward");
 digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(rightled,HIGH);
  digitalWrite(leftled,HIGH);
  digitalWrite(backled,LOW);
 }
  else{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(rightled,LOW);
  digitalWrite(leftled,LOW);
  digitalWrite(backled,LOW);
 }
 }
}
