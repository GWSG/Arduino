// 宣告一個整數陣列start，包含5個元素，分別代表星號的數量
int start[5] = {9, 7, 5, 3, 1};

void setup() {
  // 初始化串口通信，設定傳輸速率為19200 bits per second
  Serial.begin(19200);
  
  // 迴圈用於逐行輸出星號(*)圖案
  for (int i = 0; i < sizeof(start) / 2; i++) {
    // 在每行輸出指定數量的星號
    for (int j = 0; j < start[i]; j++) {
      Serial.print("*");
    }
    Serial.println(); // 換行

    // 在下一行輸出指定數量的空格，用於製造錐形效果
    for (int k = 0; k < i; k++) {
      Serial.print(" ");
    }
  }
}

void loop() {
  // 主要程式碼，空白，不執行任何動作
}
