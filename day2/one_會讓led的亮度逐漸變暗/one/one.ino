int dls;        // 宣告一個整數型別變數 dls，用於控制延遲時間
int led = 13;   // 宣告一個整數型別變數 led 並初始化為 13，代表LED所連接的引腳

void setup() {
  // 初始設定，此部分程式僅在程式啟動時執行一次：

  dls = 1;          // 設定 dls 變數為 1，用於控制延遲時間
  pinMode(led, OUTPUT);  // 設定 led 變數所代表的引腳（13號引腳）為輸出模式
}

void loop() {
  // 主要程式碼，將會反覆執行：

  digitalWrite(led, HIGH);   // 設定 13號引腳（led）為高電位（點亮LED燈）
  delay(dls);               // 延遲 dls 毫秒的時間

  digitalWrite(led, LOW);    // 設定 13號引腳（led）為低電位（熄滅LED燈）
  delay(20 - dls);          // 延遲 (20 - dls) 毫秒的時間，使亮度變暗（20 減去 dls 的值用於控制亮度）

  digitalWrite(led, LOW);    // 再次設定 13號引腳（led）為低電位
  delay(1000);              // 延遲 1000 毫秒（1秒），這是一個較長的延遲
}
