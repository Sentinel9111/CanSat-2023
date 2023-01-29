/*
Wirering:
Battery > Arduino
+ > Vin
- > gnd

APC220 > Arduino
gnd > gnd
vcc > 5V
en > Not connected
RXD > D3
TXD > D2
AUX > Not connected
SET > Not connected

BMP280 > Arduino
vcc > 3.3V
gnd > gnd
scl > D13
sda > D11
csb > D12
scd > D10
*/

/*
TO DO:
GPS
Wings
SD-Card?
*/

#include <SoftwareSerial.h> 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

const int BMP_address = 0x76;

SoftwareSerial mySerial(2,3);//RX, TX int number = 0;
int number = 0;

void setup() { 
  Serial.begin(9600);
mySerial.begin(9600);

Serial.println(F("BMP280 test"));
bmp.begin(BMP_address);
  
if (!bmp.begin(BMP_address)) {  
  Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
  while (1);
  }
}

void loop() {
String input = Serial.readString();
mySerial.println(input);

mySerial.print(F("Temperature = "));
mySerial.print(bmp.readTemperature());
mySerial.println(" *C");
    
mySerial.print(F("Pressure = "));
mySerial.print(bmp.readPressure());
mySerial.println(" Pa");

mySerial.print(F("Approx altitude = "));
mySerial.print(bmp.readAltitude(1020.00)); // this should be adjusted to your local forcase
mySerial.println(" m");
    
mySerial.println();
delay(2000);
}
