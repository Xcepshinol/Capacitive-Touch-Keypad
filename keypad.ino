#include <CapacitiveSensor.h>
CapacitiveSensor Sensor = CapacitiveSensor(8, 6);
CapacitiveSensor Sensor2 = CapacitiveSensor(8, 11);
long val;
long val2;
int pos;
#define led 2
#define led1 13

uint8_t buf[8] = {0};

void setup() {
  Serial.begin(9600);
  pinMode(led, INPUT_PULLUP);
  pinMode(led1, INPUT_PULLUP);


}

void loop() {
  val = Sensor.capacitiveSensor(30);
  val2 = Sensor2.capacitiveSensor(30);

  if (val >= 1000){
    digitalWrite(led,HIGH);
    buf[2] = 29;
    Serial.write(buf,8);
    keyRelease();
  }
    else if (val <= 1000){
    digitalWrite(led,LOW);
    keyRelease();
  }

  if (val2 >= 1000){
    digitalWrite(led1,HIGH);
    buf[2] = 27;
    Serial.write(buf,8);
    keyRelease();
  }
  else if (val2 <= 1000){
    digitalWrite(led1,LOW);
    keyRelease();
  }
  keyRelease();
}

void keyRelease(){
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf,8);

}