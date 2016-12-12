#include <Adafruit_NeoPixel.h>

#define PIN 7
#define NLED 50



Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLED, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  allcheck();

}


void allcheck(){
  int i;
  for(i=0;i<NLED;i++){
    if(i!=0){
      strip.setPixelColor(i-1,0,0,0);
    }
    strip.setPixelColor(i,255,255,255);
    strip.show();
    delay(500);
  }
  
}
