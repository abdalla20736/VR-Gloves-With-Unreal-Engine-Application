#include <WiFi.h>
#include <ArduinoJson.h>
#include <AsyncUDP.h>
#include "Simple_MPU6050.h"

#define ThumbPin 34
#define IndexPin 33
#define MiddlePin 35
#define RingPin 39
#define PinkyPin 36

float Thumb = 0;
float Index = 0;
float Middle = 0;
float Ring = 0;
float Pinky = 0;

Simple_MPU6050 mpu;




void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("\nOrientation Sensor OSC output")); Serial.println();
  connectToWifi();
  UDPConnect();
  mpu_setup();

  pinMode(ThumbPin, INPUT);        
  pinMode(IndexPin, INPUT);
  pinMode(MiddlePin, INPUT);
  pinMode(RingPin, INPUT);
  pinMode(PinkyPin, INPUT);

}


void loop(void)
{
  
  ReadFlex(Thumb, ThumbPin, "Thumb");
  ReadFlex(Index, IndexPin, "Index");
  ReadFlex(Middle, MiddlePin, "Middle");
  ReadFlex(Ring, RingPin, "Ring");
  ReadFlex(Pinky, PinkyPin, "Pinky");
  
  mpu.dmp_read_fifo(false); 

}
