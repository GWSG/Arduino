// 使用#define定義一個叫做V1的巨集，設定其值為11。在預處理階段，所有V1會被11替換。
#define V1 11 

// 使用const宣告一個名為V2的整數常數，並將其設定為22。一旦設定，V2的值就不能被改變。
const int V2 = 22;

// 宣告一個名為M的整數變數，這個變數會在稍後用來存儲計算的結果。
int M;

// setup()函數是Arduino程式的啟動點。這個函數在Arduino開機或重置後只會執行一次。
void setup() {
  // 使用Serial.begin()函數來初始化序列通訊，設定其傳輸速率為9600比特每秒。
  Serial.begin(9600);

  // 在函數內部，宣告一個名為V3的常數整數，並將其設定為33。
  const int V3 = 33;

  // 將V2和V3的值相加，然後將結果存儲到先前宣告的變數M中。
  M = V2 + V3;

  // 如果嘗試改變V2的值（如V2 = 100;），會出現編譯錯誤，因為V2是一個常數。

  // 使用Serial.println()函數將字串"HELLO"發送到串口監視器。這會在串口監視器中顯示一行"HELLO"。
  Serial.println("HELLO");

  // 使用Serial.println()函數將變數M的值（也就是V2+V3的和）發送到串口監視器。
  Serial.println(M);
}

// loop()函數會在setup()函數執行完畢後不斷循環執行。
void loop() {
  // 如果這一行取消註解，那麼字串"HELLO"會不斷地在串口監視器中顯示，因為loop()會不斷循環。
  // Serial.println("HELLO");
}
