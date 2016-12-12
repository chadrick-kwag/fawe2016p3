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

int image1_array[2][4]={ {3,255,0,0} , {4,255,0,0} };
int image1_array_size=2;


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

  if(first==0){
    Serial.println("init");
    setimg3(image1_array,100);
    event1_id=t.every(200,fadecallback);
    first=1;
    
  }
  
  
  

}

void pin_ISR(){
  Serial.println("btn1");
  bt.write('1');
//  setimg((char*)image1_array,image1_array_size);
  setimg3(image1_array,100);
  
  t.after(1000,callback1);

//  setimg2(imset1);
}


void pin_ISR2(){
  Serial.println("btn2");
  bt.write('2');

  strip.setPixelColor(0,255,0,0);
  strip.show();
  
  
}
//
//void setimg(char* image_array, int array_size){
//  
//  int i;
//  for(i=0;i<array_size;i++){
//    strip.setPixelColor(image_array[4*i+0],image_array[4*i+1],image_array[4*i+2],image_array[4*i+3]);
//
// 
//    
//  }
//
//  strip.show();
//}
//
//
//void setimg2(struct imageset input){
//  int i;
//  char* ptr=input.arrptr;
//  for(i=0;i<input.size;i++){
//    strip.setPixelColor(ptr[4*i+0],ptr[4*i+1],ptr[4*i+2],ptr[4*i+3]);
//  }
//
//  strip.show();
//}
//
//void setimg3(char fuck[2][4]){
//  int i;
//  for(i=0;i<2;i++){
//    strip.setPixelColor((int)fuck[i][0],fuck[i][1],fuck[i][2],fuck[i][3]);
//  }
//  strip.show();
//}


void setimg3(int fuck[2][4], int factor){
  int i;
  for(i=0;i<2;i++){
    strip.setPixelColor(fuck[i][0],fuck[i][1]*factor/100,fuck[i][2]*factor/100,fuck[i][3]*factor/100);
  }
  strip.show();
}

void callback1(){
  Serial.println("callback");
  
}

void fadecallback(){
  if(fade_count<5){
    setimg3(image1_array,20*(4-fade_count++));
    
  }

  if(fade_count>=5){
    t.stop(event1_id);
    fade_count=0;
  }
  
  
}

