#include "HCSR04.h"
#define Trig 2
#define Echo 3
#define Buzzer 4
HCSR04 myHC(Trig, Echo);
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int range = myHC.dist();
  Serial.print("Range="); Serial.println(range);
  if(range>50) {
    //有源蜂鳴器
    digitalWrite(Buzzer, LOW); 
  }
  else if(range>30) {
    for(int i=0; i<2; i++){
      //有源蜂鳴器
      digitalWrite(Buzzer, HIGH);
      delay(1000/2/2);
      digitalWrite(Buzzer, LOW);
      delay(1000/2/2);
    }
     delay(500);
  }
  else if(range>10) {
    for (int i=0; i<6; i++){
      //有源蜂鳴器
      digitalWrite(Buzzer, HIGH);
      delay(1000/6/2);
      digitalWrite(Buzzer, LOW);
      delay(1000/6/2);
    }
    delay(500);
  }
  else {
    //有源蜂鳴器
    digitalWrite(Buzzer, HIGH);
  }
}

