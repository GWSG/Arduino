int dls;
int led=13;
int period=20;
int i;
int j;
void setup() {
  // put your setup code here, to run once:

//第一題
  //dls=1;
  //pinMode(led, OUTPUT);

//第二題
  pinMode(led, OUTPUT); //這行是會由亮變暗
 //pinMode(period, OUTPUT);//這行是會由暗變亮
}

void loop() {
  // put your main code here, to run repeatedly:


//第一題
  //digitalWrite(led, HIGH);
  //delay(dls);

  //digitalWrite(led, LOW);
  //delay(20-dls);


 //第二題由暗變亮
  for(i=0;i<=period;i++)
  {
    digitalWrite(led, HIGH);
    delay(i);
    digitalWrite(led, LOW);
    delay(period-i);
  }

//第三題由亮變暗
  //for(j=0;j<=period;j++){
    //digitalWrite(led, HIGH);
    //delay(j);
     /*digitalWrite(led, LOW);
    delay(i-period);
    
  }
  */
   
    digitalWrite(led, LOW);
    delay(1000);

}
