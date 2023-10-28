// 宣告一個名為dls的整數變數，但這個變數在這個程式碼裡面沒有被用到
int dls;

// 宣告一個名為led的整數變數，並把它設成13。這個是連到Arduino上的那個LED燈的腳位。
int led = 13;

// 宣告一個名為period的整數變數，並把它設成20。這個數字表示LED燈會閃爍21次（從0到20）。
int period = 20;

// 宣告兩個整數變數i和j。我們會用它們來計數，看迴圈跑了多少次。
int i;
int j;

// 當Arduino一開始運行的時候，會執行一次這個setup()函數。
void setup() {
  // 把名為led的腳位設定成"輸出"模式，這樣我們就可以控制LED燈的亮或暗。
  pinMode(led, OUTPUT);
}

// 這個loop()函數會一直一直重複執行。
void loop() {
  // 這個for迴圈會從j=0數到j=20。
  for (j = 0; j <= period; j++) {
    // 這行會讓LED燈亮起來。
    digitalWrite(led, HIGH);
    
    // 這行會讓程式暫停j毫秒（0, 1, 2, ..., 20毫秒）。
    delay(j);
    
    // 這行會讓LED燈熄滅。
    digitalWrite(led, LOW);

    // 這裡有點奇怪，因為我們不知道要等多久。
    //delay(i - period);

  }
  
  // 這行確保LED燈會熄滅，不會意外地保持亮著。
  digitalWrite(led, LOW);
  
  // 這行會讓程式暫停1000毫秒，也就是1秒。
  delay(1000);
}
