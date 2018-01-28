#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <math.h>

#define TFT_DC 9
#define TFT_CS 10
#define DISPLAY_WIDTH  320
#define DISPLAY_HEIGHT 240
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

#define BOX1X 15
#define BOX1Y 15
#define BOX2X DISPLAY_WIDTH/2 + 10
#define BOX2Y 15
#define BOX3X 15
#define BOX3Y DISPLAY_HEIGHT/2 - 10
#define BOX4X DISPLAY_WIDTH/2 + 10
#define BOX4Y DISPLAY_HEIGHT/2-10

#define BOX5X DISPLAY_WIDTH/2 + 10
#define BOX5Y DISPLAY_HEIGHT-40

// These are the four touchscreen analog pins
#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 5   // can be a digital pin
#define XP 4   // can be a digital pin

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

#define SERVOSTOP 93
#define SERVOBACK 180
#define SERVOFOR 20



#define SERSPEED 8.7022

Servo myservo;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int DRINK;

void setup(){
	init();
	tft.begin();
	Serial.begin(9600);
	Serial.println("Initializing...");
	tft.setRotation(3);
	myservo.attach(8);
}

void rotate(int size, int DRINK){
	int moveTime = 73;//(s)
	Serial.print("rotate to position: ");
	Serial.println(DRINK);
	if(DRINK == 1){
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);

		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
	}
	else if(DRINK == 2){
		moveTime = 3*moveTime-50;
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
	}
	else if(DRINK == 3){
		moveTime = 5*moveTime-100;
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
	}
	else if(DRINK == 4){
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);		

		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOBACK);
		}
	}
	else if(DRINK == 5){
		//slot1/2
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		//slot1/2
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(4000);
		moveTime = 3*moveTime-50;
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOBACK);
		}

	}
	else if(DRINK == 7){
		//slot1/2/3
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		moveTime = 5*moveTime-100;
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOBACK);
		}



	}
	else if(DRINK == 8){
		//slot 1/2/3/4
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
		myservo.write(SERVOSTOP);
		delay(2000);
		for(int i = 0; i < moveTime; ++i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}

	}
	else if(DRINK == 9){
		//this will ruin the machine and need a reset
		tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
		tft.setTextColor(ILI9341_RED);
		tft.print("Despensing...RIP");
		tft.setTextColor(ILI9341_WHITE);
		delay(1000);
		int timer = 5000;

		for(int i = 0; i < timer; ++i){
			myservo.write(0);
		}
	}


	myservo.write(SERVOSTOP);

	Serial.println(moveTime);
	if(size == 1){
		delay(2000);
	}
	else if(size == 2){
		delay(3000);
	}
	else if(size == 3){
		delay(4000);
	}
	if(DRINK != 4 & DRINK != 3){
		for(int i = moveTime; i > 0; --i){
			Serial.println(i);
			myservo.write(SERVOBACK);
		}
	}
	else if(DRINK == 4){
		for(int i = 73; i > 0; --i){
			Serial.println(i);
			myservo.write(SERVOFOR);
		}
	}
	else if(DRINK == 3){
		for(int i = 175; i > 0; --i){
			Serial.println(i);
			myservo.write(SERVOBACK);
 
		}
	}
	

	Serial.println("Here");

	myservo.write(SERVOSTOP);


}

void mixers(){
	tft.fillScreen(ILI9341_BLACK);
	//mixers include mr. lahey, combination of the slots
	//(1,2),(1,2,3),(1,2,3,4),(Lahey)
	tft.drawRect(20,DISPLAY_HEIGHT/4-50,DISPLAY_WIDTH-40,40,ILI9341_WHITE);
	tft.drawRect(20,DISPLAY_HEIGHT/4+10,DISPLAY_WIDTH-40,40,ILI9341_WHITE);
	tft.drawRect(20,DISPLAY_HEIGHT/4+70,DISPLAY_WIDTH-40,40,ILI9341_WHITE);
	tft.drawRect(20,DISPLAY_HEIGHT/4+130,DISPLAY_WIDTH-40,40,ILI9341_WHITE);
	
	tft.setCursor(DISPLAY_WIDTH/4-40,20);
	tft.print("Slot 1 1/2(1oz,3oz)");
	tft.setCursor(DISPLAY_WIDTH/4-50,80);
	tft.print("Slot 1/2/3(1oz,1oz,1oz");
	tft.setCursor(DISPLAY_WIDTH/4-40,140);
	tft.print("Slot 1/2/3/4(1oZ)");
	tft.setCursor(DISPLAY_WIDTH/4-40,200);
	tft.print("Mr. Lahey's Special");

	while(true){
		TSPoint p = ts.getPoint();

		if(p.z != 0){
			Serial.println(p.x);
			Serial.println(p.y);
			
			if(p.y < 850 && p.y > 150){
				if(p.x > 200 && p.x < 300){
					//slot1/2
					DRINK = 5;
					tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
					tft.setTextColor(ILI9341_RED);
					tft.print("Despensing...");
					tft.setTextColor(ILI9341_WHITE);
					delay(1000);
				}
				else if(p.x > 400 && p.x < 500){
					//slot1/2/3
					DRINK = 6;
					tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
					tft.setTextColor(ILI9341_RED);
					tft.print("Despensing...");
					tft.setTextColor(ILI9341_WHITE);
					delay(1000);
				}
				else if(p.x > 600 && p.x < 700){
					//slot1/2/3
					DRINK = 7;
					tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
					tft.setTextColor(ILI9341_RED);
					tft.print("Despensing...");
					tft.setTextColor(ILI9341_WHITE);
					delay(1000);
				}
				else if(p.x > 800 && p.x < 900){
					//mr lahey
					DRINK = 8;
					tft.setCursor(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2);
					tft.setTextColor(ILI9341_RED);
					tft.print("Despensing...");
					tft.setTextColor(ILI9341_WHITE);
					delay(1000); 
				}
			}
			
		}

	}
}


void displayMenu(){
	tft.fillScreen(ILI9341_BLACK);

	tft.fillRect(5,5,DISPLAY_WIDTH-10,DISPLAY_HEIGHT-10,ILI9341_WHITE);
	tft.fillRect(7,7,DISPLAY_WIDTH-14,DISPLAY_HEIGHT-14,ILI9341_BLACK);
	tft.drawRect(BOX1X,BOX1Y,135,80,ILI9341_WHITE);
	tft.drawRect(BOX2X,BOX2Y,135,80,ILI9341_WHITE);
	tft.drawRect(BOX3X,BOX3Y,135,80,ILI9341_WHITE);
	tft.drawRect(BOX4X,BOX4Y,135,80,ILI9341_WHITE);
	tft.drawRect(BOX5X,BOX5Y,130,30,ILI9341_RED);


	//drawing in text
	tft.setCursor(DISPLAY_WIDTH/4-40,DISPLAY_HEIGHT/4 - 10);
	tft.setTextSize(2);
	tft.print("Drink 1");
	tft.setCursor(DISPLAY_WIDTH/2+30,DISPLAY_HEIGHT/4 - 10);
	tft.print("Drink 2");
	tft.setCursor(DISPLAY_WIDTH/4-40,DISPLAY_HEIGHT/2+20);
	tft.print("Drink 3");
	tft.setCursor(DISPLAY_WIDTH/2+30,DISPLAY_HEIGHT/2+20);
	tft.print("Drink 4");
	tft.setCursor(DISPLAY_WIDTH/2+30,DISPLAY_HEIGHT-30);
	tft.print("Mixes");

	
	bool selection = false;
	
	

	while(!selection){

		TSPoint p = ts.getPoint();

		if(p.z != 0){
			
			if(p.x > 200 && p.x < 380){
				if(p.y > 550 && p.y < 825){
					//drink 1 selected
					
					selection = true;
					DRINK = 1;

				}
				else if(p.y >150 && p.y < 400){
					//drink 2 selected
					
					selection = true;
					DRINK = 2;
				}

			}
			else if(p.x > 550 && p.x < 730){
				if(p.y > 550 && p.y < 825){
					//drink 3 selected
					
					selection = true;
					DRINK = 3;
				}
				else if(p.y > 150 && p.y < 400){
					//drink 4 selected;
					selection = true;
					DRINK = 4;
				}
			}
			else if(p.y > 170 && p.y < 400 && p.x > 780 && p.x < 850){
				//mixer selected
				
				selection = true;
				mixers();
				
			}

		}

		
	}


}

void drawSizes(int DRINK){

	tft.fillScreen(ILI9341_BLACK);
	tft.setCursor(DISPLAY_WIDTH/4-20,DISPLAY_HEIGHT/6);
	tft.print("Youve selected: ");
	tft.print(DRINK);
	tft.setCursor(DISPLAY_WIDTH/4-10,DISPLAY_HEIGHT/4);
	tft.print("Chose amount");

	tft.drawRect(5,DISPLAY_HEIGHT/2,100,60,ILI9341_WHITE);
	tft.drawRect(113,DISPLAY_HEIGHT/2,100,60,ILI9341_WHITE);
	tft.drawRect(220,DISPLAY_HEIGHT/2,100,60,ILI9341_WHITE);
	tft.setCursor(20,DISPLAY_HEIGHT/2+10);
	tft.print("1oz");
	tft.setCursor(125,DISPLAY_HEIGHT/2+10);
	tft.print("2oz");
	tft.setCursor(230,DISPLAY_HEIGHT/2+10);
	tft.print("3oz");	

	

	delay(2000);
	
}

int selectSize(){
	

	while(true){
		TSPoint p = ts.getPoint();
		
		if(p.x > 500 && p.x < 750){
			if(p.y > 700 && p.y < 800){
				//small size
				tft.setCursor(DISPLAY_WIDTH/3-10,DISPLAY_HEIGHT-40);
				tft.print("Too small");
				return 1;
			}
			else if(p.y > 400 && p.y < 600){
				//medium size
				tft.setCursor(DISPLAY_WIDTH/3-10,DISPLAY_HEIGHT-40);
				tft.print("Getting better");
				return 2;
			}
			else if(p.y > 100 && p.y < 300){
				//large size 
				tft.setCursor(DISPLAY_WIDTH/3-10,DISPLAY_HEIGHT-40);
				tft.print("Thats more like it");
				return 3;
			}
		}
		
	}
}

void vendDrink(int size, int DRINK){

	Serial.println(DRINK);
	
	//using the drink and the size of the pour, move to that location,
	//from starting(45 degrees) to the hole(0,90,180,270)
	//in the shortest time(by measuring arclength and going forwards or)
	//backwards, it then returns to its normal position at 45 degrees

	rotate(size, DRINK);


	// while(true){
	// 	myservo.write(SERVOFOR);
	// }
		


}

int main(){
	/*GENERAL OVERVIEW:
		1.Check if touchscreen has been pressed 
		2.If touchscreen pressed, see what has been selected
		3.Move servo to that position for time that has been specified
		by the selection
		4.Return servo to position 45 degrees between holes
	*/
	setup();
	

	while(true){
		displayMenu();

		drawSizes(DRINK);

		int size = selectSize();

		vendDrink(size, DRINK);

	}


	Serial.end();
	return 0;
}