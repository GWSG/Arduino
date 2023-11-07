// 定義七段顯示器的第一個段（A段）連接到Arduino的第2腳位
#define seg7_a 2  

// 初始化七段顯示器的蛇行燈順序，用二進制表示每一個段的狀態（開或關）
int seg7_digit[8] = {B10000000, B01000000, B00000010, B00001000, B00010000, B00100000, B00000010, B00000100};

// 初始化用來控制共陰極（或共陽極）的腳位編號
int digits[4] = {10, 11, 12, 13};  

// 定義延遲時間（毫秒），用於控制蛇行燈的切換速度
int delayTime = 100;  

// setup() 函數，在程式開始時運行一次
void setup() {
  // 初始化七段顯示器的所有腳位
  for (int i = 0; i < 8; i++) {
    pinMode(seg7_a + i, OUTPUT);  // 將每個腳位設為輸出模式
    digitalWrite(seg7_a + i, LOW);  // 將每個腳位初始化為低電平（熄滅狀態）
  }
  // 初始化用於控制共陰極（或共陽極）的腳位
  for (int i = 0; i < 4; i++) {
    pinMode(digits[i], OUTPUT);  // 將每個腳位設為輸出模式
    digitalWrite(digits[i], HIGH);  // 將每個腳位初始化為高電平（熄滅狀態）
  }
  // 預先開啟第一個共陰極
  digitalWrite(digits[0], LOW);  
}

// loop() 函數，一直循環運行
void loop() {
  // 逐一遍歷所有定義的蛇行燈模式
  for (int i = 0; i < 8; i++) {
    show(seg7_digit[i]);  // 調用 show 函數來顯示當前的模式
    delay(delayTime);  // 延遲以控制速度
    clearDisplay();  // 清除顯示器
    delay(delayTime);  // 再次延遲以控制速度
  }
}

// show 函數，用於顯示單個蛇行燈模式
void show(int val) {
  int mask0 = B10000000;  // 初始化掩碼，用於逐一檢查每一個段
  int mask;  // 存儲當前的掩碼

  // 遍歷所有的七段顯示器段
  for (int i = 0; i < 8; i++) {
    mask = mask0 >> i;  // 將掩碼向右位移，對應到下一個段
    // 使用位元運算子 '&' 來檢查目標段是否應該是開（HIGH）或關（LOW）
    if (val & mask) digitalWrite(seg7_a + i, HIGH);  // 如果是，設為高電平
    else digitalWrite(seg7_a + i, LOW);  // 否則，設為低電平
  }
}

// clearDisplay 函數，用於關閉所有的七段顯示器段
void clearDisplay() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(seg7_a + i, LOW);  // 將所有段設為低電平（熄滅狀態）
  }
}
