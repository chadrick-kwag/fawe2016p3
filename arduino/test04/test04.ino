#include <TimerOne.h>

/*
 * 
 * 
 * using different timer library
 */


#include <Adafruit_NeoPixel.h>


#include <SoftwareSerial.h>



SoftwareSerial bt(10,11); // rx,tx

#define NLED 50

#define BUTTON1 2
#define BUTTON2 3

#define PIN 6

#define IMGARR_1_SIZE 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLED, PIN, NEO_GRB + NEO_KHZ800);

int image1_array[IMGARR_1_SIZE][4]={ {47,150,150,150} , {46,150,150,150} , {45,150,150,150} , {44,150,150,150} , {43,150,150,150}, {42,150,150,150} };



int image2_array[5][4]{ {0,0,255,0} , {1,0,255,0} , {13,0,0,255} , {20,0,0,255} , {27,0,0,255} };



//

void add_sched(int sched_times_slot, int after_ticks, void* callbackfunction);
void callback3(void);

typedef void (*funcptr)();


long sched_times[5]={0,0,0,0,0};
funcptr sched_callbacks[5]={0,0,0,0,0};

struct imageset{
  int size;
  char* arrptr;
};

struct imageset imset1={2,(char*)image1_array};








int fade_count=0;
int event1_id=-1;
long timer_tick=0;


void timer_callback(void){

  timer_tick++;
}

int first=0;


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

  Timer1.initialize(10000); // 10ms
  Timer1.attachInterrupt(timer_callback);

}


void loop() {
  // put your main code here, to run repeatedly:

  schedule();

}


/*
 * 
 * 
 */

void pin_ISR(){
  Serial.println("btn1");
  bt.write('1');
 
  
  setimg3(image1_array,100);
  add_sched(0,100,callback3); 

}


void pin_ISR2(){
  Serial.println("btn2");
  bt.write('2');
//
//  setimg3(image2_array,100);
//  t.after(100,fadecallback2);
//  
  
}


void setimg3(int fuck[IMGARR_1_SIZE][4], int factor){
  int i;
  for(i=0;i<IMGARR_1_SIZE;i++){
    strip.setPixelColor(fuck[i][0],fuck[i][1]*factor/100,fuck[i][2]*factor/100,fuck[i][3]*factor/100);
  }
  strip.show();
}

void callback1(){
  Serial.println("callback");
  
}

//
//void fadecallback(){
//  if(event1_id==-1){
//    
//  }
//
//  if(fade_count<5){
//    setimg3(image1_array,(4-fade_count++)*20);
//    Serial.print(event1_id);
//    
//  }
//  if(fade_count>=5){
//    fade_count=0;
//    t.stop(event1_id);
//    event1_id=-1;
//  }
//  
//  setimg3(image1_array,0);
//  Serial.println("callback"); 
//  
//}

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


void schedule(void){
  int i;
  funcptr tempfptr;
  for(i=0;i<5;i++){
    if( timer_tick > sched_times[i]){
      sched_times[i]=0;
      tempfptr = sched_callbacks[i];
      tempfptr();
      sched_callbacks[i]=0;
    }
  }

}

void add_sched(int sched_times_slot, long after_ticks, void* callbackfunction){
  sched_times[sched_times_slot]=timer_tick+after_ticks;
  sched_callbacks[sched_times_slot]=callbackfunction;
}



void callback3(void){
  Serial.println("callback3 trigger");
}



