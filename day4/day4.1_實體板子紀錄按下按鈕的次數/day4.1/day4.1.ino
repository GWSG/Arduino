// 定義按鈕腳位，將其設為2號腳位
#define ButtonPin 2

// 宣告一個名為cnt的整數變數，用於儲存計數值
int cnt;

// 宣告一個名為flag的整數變數，用於防止連續多次增加計數
int flag;

void setup() {
  // 通過Serial.begin()初始化串口通信，設定傳輸速率為9600 bps
  Serial.begin(9600);

  // 將ButtonPin腳位設為輸入模式，並啟用內部上拉電阻，這樣按鈕未按下時會讀取為HIGH
  pinMode(ButtonPin, INPUT_PULLUP);

  // 初始化cnt變數為0，表示開始時計數為0
  cnt = 0;

  // 初始化flag變數為0，表示開始時還沒有按過按鈕
  flag = 0;

  // 透過串口輸出，將cnt變數的初始值輸出至電腦端
  Serial.print("計算值=");
  Serial.println(cnt);
}

void loop() {
  // 主函式，Arduino會不斷重複執行此函式

  // 讀取ButtonPin腳位的狀態，如果為HIGH（未按下），則將flag設為0
  if (digitalRead(ButtonPin) == HIGH)
    flag = 0;

  // 讀取ButtonPin腳位的狀態，如果為LOW（按下）且flag為0（之前沒有按下過或已經放開）
  if (digitalRead(ButtonPin) == LOW && flag == 0) {
    // 將cnt變數加1，表示按鈕被按下了一次
    cnt++;

    // 透過串口輸出，將新的cnt變數值輸出至電腦端
    Serial.print("計數值=");
    Serial.println(cnt);

    // 將flag設為1，防止在按鈕持續被按下的狀態下重複增加cnt
    flag = 1;
  }
}
