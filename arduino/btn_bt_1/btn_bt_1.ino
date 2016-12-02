#include <Adafruit_NeoPixel.h>

#include <Event.h>
#include <Timer.h>

#include <SoftwareSerial.h>



SoftwareSerial bt(10,11); // rx,tx

#define NLED 6

#define BUTTON1 2
#define BUTTON2 3

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLED, PIN, NEO_GRB + NEO_KHZ800);

char image1[NLED][3]={ {0,0,255}, {0,0,255} , {0,122,122} , {0,122,200} , {0,255,0} , {255, 120, 0} };


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("serial start");
  bt.begin(9600);

  strip.begin();


  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  attachInterrupt(0,pin_ISR,FALLING);
  attachInterrupt(1,pin_ISR2,FALLING);

  

}

void loop() {
  // put your main code here, to run repeatedly:

}

void pin_ISR(){
  Serial.println("btn1");
  bt.write('1');
  setimg(image1);
  
}


void pin_ISR2(){
  Serial.println("btn2");
  bt.write('2');

  strip.setPixelColor(0,255,0,0);
  strip.show();
  
}

void setimg(char image[NLED][3]){
  int i=0;
  for(i=0;i<NLED;i++){
    strip.setPixelColor(i,image[i][0],image[i][1],image[i][2]);
  }

  strip.show();
}

