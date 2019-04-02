#include <SoftwareSerial.h>

SoftwareSerial nodemcu(2,3);

int parking1_slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 5;

String sensor1;
String sensor2;


String cdata =""; // complete data, consisting of sensors values

void setup()
{
Serial.begin(9600);
nodemcu.begin(9600);

pinMode(parking1_slot1_ir_s, INPUT);
pinMode(parking1_slot2_ir_s, INPUT);


}

void loop()
{

p1slot1();
p1slot2();

 
 
   cdata = cdata + sensor1 +"," + sensor2 + ","; // comma will be used a delimeter
   Serial.println(cdata);
   nodemcu.println(cdata);
   delay(6000); // 100 milli seconds
   cdata = "";
digitalWrite(parking1_slot1_ir_s, HIGH);
digitalWrite(parking1_slot2_ir_s, HIGH);
}


void p1slot1() // parkng 1 slot1
{
  if( digitalRead(parking1_slot1_ir_s) == LOW)
  {
  sensor1 = "255";
 delay(200);
  }
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  sensor1 = "0"; 
 delay(200); 
}

}

void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW)
  {
  sensor2 = "255";
  delay(200);
  }
if( digitalRead(parking1_slot2_ir_s) == HIGH) 
  {
  sensor2 = "0"; 
 delay(200);
  }
}
