const int buttonPin = 2; 
const int ledPin = 13;   

int buttonState = HIGH; 
int lastButtonState = HIGH; 
int buttonPressCount = 0; 

void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 
}

void loop() {
  buttonState = digitalRead(buttonPin); // 讀取按鈕狀態

  // 如果按鈕由高到低的邊緣觸發
  if (buttonState == LOW && lastButtonState == HIGH) {
    buttonPressCount++; // 按鈕按下時次數加1
    performAction(); // 執行相應的動作
  }

  lastButtonState = buttonState; // 更新按鈕的上一個狀態
}

void performAction() {
  switch (buttonPressCount) {
    case 1:
      digitalWrite(ledPin, HIGH); // 點亮LED
      delay(1000); // 延遲1秒
      digitalWrite(ledPin, LOW); // 關閉LED
      break;
    case 2:
      for (int i = 0; i < 2; i++) {
        digitalWrite(ledPin, HIGH); // 點亮LED
        delay(1000); // 延遲1秒
        digitalWrite(ledPin, LOW); // 關閉LED
        delay(1000); // 延遲1秒
      }
      break;
    case 3:
      for (int i = 0; i < 3; i++) {
        digitalWrite(ledPin, HIGH); // 點亮LED
        delay(1000); // 延遲1秒
        digitalWrite(ledPin, LOW); // 關閉LED
        delay(1000); // 延遲1秒
      }
      break;
    case 4:
      digitalWrite(ledPin, LOW); // 關閉LED
      delay(5000); // 延遲5秒
      //digitalWrite(ledPin, HIGH); // 點亮LED
      //delay(300); // 延遲0.3秒
      //digitalWrite(ledPin, LOW); // 關閉LED
      buttonPressCount = 0;
      break;
  }
}

// 第1行 buttonPin 是连接到按钮的数字引脚。

// 第2行 ledPin 是连接到LED的数字引脚。

// 第3行 按鈕的初始狀態,初始为高電平（HIGH）。

// 第4行 按鈕的上一個狀態

// 第5行 按鈕按下的次數,一開始先設為0

// 第8行 setup 函数在Arduino啟動時運行,初始化的設置。

// 第9行  設置按鈕接腳為INPUT,並按下按鈕引腳設置為輸入模式,並啟用內部上拉電阻,避免按鈕沒按時誤觸發

// 第10行 設置LED接腳為OUTPUT

// 第11行 初始狀態關閉LED,設置為低電平(LED關閉)

// 第15行 digitalRead(buttonPin) 讀取到按钮引脚的状态，並將结果存在 buttonState 中。

// 18到21行 if 语句检查按钮是否由高電平轉為低電平（即，是否按下按钮）。
//如果按钮按下，buttonPressCount 增加1，並啟動 performAction() 函数裡的操作。

// 第23行 將 lastButtonState 更新當前按鈕案的次數的狀態,這樣 performAction 才可以準備下一次按鈕次數的操作

// 第26行 會因為buttonPressCount的數值,而啟動performAction()裡不同次數的操作
//像是如果數值是1,就啟動performAction()數值1裡的指令
//像是如果數值是2,就啟動performAction()數值2裡的指令

//第27行 用於根據buttonPressCount變數的值來執行不同的程式碼區塊。switch語句允許當道某個表達式的值，就會啟動當下那個值要做的事情



