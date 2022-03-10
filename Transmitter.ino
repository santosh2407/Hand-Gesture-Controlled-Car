#include<Wire.h>
#include <VirtualWire.h>
char *data;
const int MPU=0x68; 
int16_t AcX,AcY,Tmp;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  vw_set_tx_pin(12);
  vw_setup(2000);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  if(AcY <= -8000)
  {
    data="F";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else if(AcY >= 10000)
  {
    data="B";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx(); 
  }
  else if(AcX <= -8000)
  {
    data="R";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx(); 
  }
  else if(AcX >= 8000)
  {
    data="L";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else 
  {
    data="S";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx(); 
  }
  Serial.print("X=");
  Serial.println(AcX);
  Serial.print("Y=");
  Serial.println(AcY);
}
