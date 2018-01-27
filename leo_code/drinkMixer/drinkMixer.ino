#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>

#define TFT_DC 9
#define TFT_CS 10


Servo myservo;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);


int pos = 0;

void setup(){
	init();
	tft.begin();
	Serial.begin(9600);
	Serial.println("Initializing...");
}

void loop(){

}