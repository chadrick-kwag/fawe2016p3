#define BUTTON1 2
#define BUTTON2 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("serial start");


  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2,INPUT);
  attachInterrupt(0,pin_ISR,FALLING);
  attachInterrupt(1,pin_ISR2,FALLING);

  

}

void loop() {
  // put your main code here, to run repeatedly:

}

void pin_ISR(){
  Serial.println("btn1 pressed");
  
}


void pin_ISR2(){
  Serial.println("btn2 pressed");
  
}

