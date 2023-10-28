int dls;         // 宣告一個整數型變數 dls，用於控制延遲時間
int led = 13;    // 宣告一個整數型變數 led 並初始化為 13，代表LED所連接的引腳
int period = 20; // 宣告一個整數型變數 period 並初始化為 20，代表週期的長度
int i;           // 宣告一個整數型變數 i，用於循環計數

void setup() {
  // 初始設定，此部分程式僅在程式啟動時執行一次：

  // 第二題：將連接到 led 引腳的引腳設定為輸出模式
  pinMode(led, OUTPUT);
}

void loop() {
  // 主要程式碼，將會反覆執行：

  // 第二題：透過循環，控制LED的亮度逐漸由暗變亮
  for (i = 0; i <= period; i++) {
    digitalWrite(led, HIGH);  // 設定 13號引腳（led）為高電位（點亮LED燈）
    delay(i);                // 延遲 i 毫秒的時間

    digitalWrite(led, LOW);   // 設定 13號引腳（led）為低電位（熄滅LED燈）
    delay(period - i);        // 延遲 (period - i) 毫秒的時間，使亮度逐漸變亮

    // 以上的操作將重複執行，i 從 0 遞增到 period，LED的亮度會逐漸由暗變亮

    digitalWrite(led, LOW);  // 再次設定 13號引腳（led）為低電位（熄滅LED燈）
    delay(1000);            // 延遲 1000 毫秒（1秒）
  }
}
