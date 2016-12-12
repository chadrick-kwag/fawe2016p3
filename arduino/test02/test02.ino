#include <Adafruit_NeoPixel.h>

#include <Event.h>
#include <Timer.h>

#include <SoftwareSerial.h>



SoftwareSerial bt(10,11); // rx,tx

#define NLED 50

#define BUTTON1 2
#define BUTTON2 3

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLED, PIN, NEO_GRB + NEO_KHZ800);

int image1_array[5][4]={ {3,255,0,0} , {4,255,0,0} , {10,255,0,0} , {15,255,0,0} , {25,255,0,0} };
int image1_array_size=2;


int image2_array[5][4]{ {0,0,255,0} , {1,0,255,0} , {13,0,0,255} , {20,0,0,255} , {27,0,0,255} };


struct imageset{
  int size;
  char* arrptr;
};

struct imageset imset1={2,(char*)image1_array};


int fade_count=0;
int event1_id=0;


Timer t;


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
int first=0;

void loop() {
  // put your main code here, to run repeatedly:

  t.update();




}


/*
 * 
 * 
 */

void pin_ISR(){
  Serial.println("btn1");
  bt.write('1');
  setimg3(image1_array,100);
  event1_id=t.after(1000,fadecallback);
  
}


void pin_ISR2(){
  Serial.println("btn2");
  bt.write('2');

  setimg3(image2_array,100);
  t.after(100,fadecallback2);
  
  
}


void setimg3(int fuck[5][4], int factor){
  int i;
  for(i=0;i<5;i++){
    strip.setPixelColor(fuck[i][0],fuck[i][1]*factor/100,fuck[i][2]*factor/100,fuck[i][3]*factor/100);
  }
  strip.show();
}

void callback1(){
  Serial.println("callback");
  
}


void fadecallback(){
  setimg3(image1_array,0);
  Serial.println("callback"); 
  
}

void fadecallback2(){
  setimg3(image2_array,0);
  
}

void allcheck(){
  int i;
  for(i=0;i<NLED;i++){
    if(i!=0){
      strip.setPixelColor(i-1,0,0,0);
    }
    strip.setPixelColor(i,255,255,255);
    strip.show();
    delay(1000);
  }
  
}


