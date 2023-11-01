// 定義LED腳位和按鈕腳位
#define LedPin 13
#define BtnPin 2

// 計數器變數
int cnt;

// 標誌變數，用於確保每次按下按鈕只增加一次計數
int flag;

// 變數用於去彈跳
int lastDebounceTime; // 上一次去彈跳的起始時間
int debounceDelay;    // 去彈跳的延遲時間
int btnState;         // 目前按鈕狀態
int lastBtnState = HIGH; // 上一次的按鈕狀態，預設為未按下

void setup() {
  // 初始化串口通信，設定傳輸速率為9600 bits per second
  Serial.begin(9600);

  // 設定BtnPin腳位為輸入模式，並啟用內部上拉電阻
  pinMode(BtnPin, INPUT_PULLUP);

  // 設定LedPin腳位為輸出
  pinMode(LedPin, OUTPUT);

  // 將LedPin設為低電位，LED熄滅
  digitalWrite(LedPin, LOW);

  // 初始化計數器為0
  cnt = 0;

  // 初始化標誌變數為0
  flag = 0;

  // 初始化去彈跳相關變數
  lastDebounceTime = 0;
  debounceDelay = 50; // 去彈跳的延遲時間為50毫秒
}

void loop() {
  // 主要程式碼，重複執行

  // 去彈跳機制開始

  // 讀取按鈕腳位的狀態
  int reading = digitalRead(BtnPin);

  // 如果當前狀態與上一次按鈕狀態不同，則更新去彈跳起始時間
  if (reading != lastBtnState) {
    lastDebounceTime = millis();
  }

  // 如果經過了足夠的時間（去彈跳延遲時間），則更新按鈕狀態
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != btnState) {
      btnState = reading;
    }
  }

  // 更新上一次的按鈕狀態
  lastBtnState = reading;

  // 去彈跳機制結束

  // 如果按鈕按下（LOW）且標誌為0（未計數）
  if (btnState == LOW && flag == 0) {
    digitalWrite(LedPin, HIGH); // 点亮LED
    cnt++;                      // 增加計數器
    flag = 1;                   // 設定標誌為1（已計數）
    Serial.print("Counter = ");
    Serial.println(cnt);         // 在串口上輸出計數值
  } else {
    digitalWrite(LedPin, LOW); // 關閉LED
    flag = 0;                  // 設定標誌為0（未計數）
  }
}
