#define led 13
#define Btn 2
#define deBounceTime 200

volatile int cnt=0;
volatile unsigned long now=0 , pre=0;
//tkjgoijhtosijs
//ls;lk;hfykljc';
//dklgdkltyk;jlkf;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(Btn, INPUT_PULLUP);
  digitalWrite(led, LOW);
  sei();
  EIMSK = 0x01;
  EICRA = 0x02;
 
}

void loop() {
  // put your main code here, to run repeatedly:
}

ISR(INT0_vect){
  now = millis();
  if((now-pre)<deBounceTime) { pre = now; return; }
  digitalWrite(led, !digitalRead(led));
    cnt++;
     Serial.println(cnt);
  pre = now;

}
