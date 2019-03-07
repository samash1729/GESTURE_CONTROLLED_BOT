#include <SoftwareSerial.h>
SoftwareSerial bt(2,3); //Rx && Tx
int val,val2;
//For Right Tyres
int set_pin1 = 5 ; //Speed Vary
int rm1 = 6 ;
int rm2 = 4 ;
//For Left Tyres
int lm1 = 7 ;
int lm2 = 8 ;
int set_pin2 = 9 ; //Speed Vary
void setup() {
  
  Serial.begin(9600);
  bt.begin(38400);
  pinMode(set_pin1,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(set_pin2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);

}
void loop()
{
    while(bt.available()==0);
    val = bt.read();
   // Serial.print(val);
    //Serial.print("  ");
    while(bt.available()==0);
    val2 = bt.read();
    //Serial.println(val2);
    if(val2==0 && val==0)
    {
        digitalWrite(rm1,LOW);
        digitalWrite(rm2,LOW);
        digitalWrite(lm1,LOW);
        digitalWrite(lm2,LOW);
    }
    else
    {
      if( (val2==1 || val2==2 || val2==3 || val2==255 || val2==254 || val2==253) && val==0 )
      {
        switch(val2)
        {
          case 1 : digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,120);
                   digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,120);
                   break;
          case 2 : digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,180);
                   digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,180);
                   break;
          case 3 : digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,255);
                   digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,255);
                   break;
        case 255 : digitalWrite(rm1,LOW);
                   digitalWrite(rm2,HIGH);
                   analogWrite(set_pin1,120);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,HIGH);
                   analogWrite(set_pin2,120);
                   break;
        case 254 : digitalWrite(rm1,LOW);
                   digitalWrite(rm2,HIGH);
                   analogWrite(set_pin1,180);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,HIGH);
                   analogWrite(set_pin2,180);
                   break;
        case 253 : digitalWrite(rm1,LOW);
                   digitalWrite(rm2,HIGH);
                   analogWrite(set_pin1,255);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,HIGH);
                   analogWrite(set_pin2,255);
                   break;
         default : break;
        }
      }
      if( (val==1 || val==2 || val==3 || val==255 || val==254 || val==253) && val2==0 )
      {
        switch(val)
        {
          case 1 : digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,175);
                   digitalWrite(rm1,LOW);
                   digitalWrite(rm2,LOW);
                   break;
          case 2 : digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,255);
                   digitalWrite(rm1,LOW);
                   digitalWrite(rm2,LOW);
                   break;
          case 3 : digitalWrite(lm1,HIGH);
                   digitalWrite(lm2,LOW);
                   analogWrite(set_pin2,255);
                   digitalWrite(rm1,LOW);
                   digitalWrite(rm2,HIGH);
                   analogWrite(set_pin1,255);
                   break;
       case 255 :  digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,175);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,LOW);
                   break;
        case 254 : digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,255);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,LOW);
                   break;
        case 253 : digitalWrite(rm1,HIGH);
                   digitalWrite(rm2,LOW);
                   analogWrite(set_pin1,255);
                   digitalWrite(lm1,LOW);
                   digitalWrite(lm2,HIGH);
                   analogWrite(set_pin2,255);
                   break;
         default  : break;
        }
      }
    }                 
}
