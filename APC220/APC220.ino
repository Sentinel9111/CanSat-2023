#include <SoftwareSerial.h> 

SoftwareSerial mySerial(9,10);//RX, TX int number = 0;
int number = 0;

void setup() { 
  Serial.begin(9600);
mySerial.begin(9600); }

void loop() {
String input = Serial.readString();
mySerial.println(input);
}