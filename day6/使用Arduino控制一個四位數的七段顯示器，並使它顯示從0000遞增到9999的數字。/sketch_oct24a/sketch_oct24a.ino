#define seg7_a 2  // 定義七段顯示器的起始腳位為2（A段）

// 初始化七段顯示器數字0-9的編碼
int seg7_digit[10] = {0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe4, 0xfe, 0xf6};

// 初始化用於控制共陰極的Arduino腳位編號
int digits[4] = {10, 11, 12, 13};

// 定義一個用於儲存時間的變數
unsigned long t0;

// Arduino的setup函數，只運行一次
void setup()
{
 // 使用for循環來初始化七段顯示器的8個腳位（A-G和DP）
for (int i = 0; i < 8; i++) 
{
  pinMode(seg7_a + i, OUTPUT);  // 將七段顯示器的第i個腳位設定為輸出模式
  digitalWrite(seg7_a + i, LOW);  // 初始化第i個腳位為LOW（關閉狀態）
}

// 使用for循環來初始化控制七段顯示器的共陰極（Common Cathode）的4個腳位
for (int i = 0; i < 4; i++) 
{
  pinMode(digits[i], OUTPUT);  // 將共陰極的第i個腳位設定為輸出模式
  digitalWrite(digits[i], HIGH);  // 初始化第i個腳位為HIGH（關閉該數字顯示）
}
}

// 定義一個名為hide_seg7的函數，用於關閉所有的七段顯示器
void hide_seg7()
{
  // 使用for循環遍歷共陰極的4個腳位
  for (int i = 0; i < 4; i++) 
  {
    // 將第i個共陰極腳位設為HIGH，關閉該位的數字顯示
    digitalWrite(digits[i], HIGH);
  }
}


// 定義一個名為show的函數，用於顯示數字和（可選的）小數點
// val是要顯示的數字的七段編碼，decimal決定是否顯示小數點
void show(int val, bool decimal = false)
{
  int mask0 = 0x80;  // 初始化一個名為mask0的整數變量，設為0x80（即二進制的10000000）
  int mask;  // 宣告一個名為mask的整數變量

  // 使用for循環遍歷七段顯示器的每一個段（共8段，包括小數點）
  for (int i = 0; i < 8; i++) 
  {
    mask = mask0 >> i;  // 透過右移運算將mask0右移i位，並存儲結果到mask

    // 使用位元AND運算(&)來檢查第i個段是否應該是開（HIGH）或關（LOW）
    if (val & mask) 
      digitalWrite(seg7_a + i, HIGH);  // 如果是，設置對應的Arduino腳位為HIGH
    else 
      digitalWrite(seg7_a + i, LOW);  // 如果不是，設置對應的Arduino腳位為LOW
  }
  
  // 檢查是否需要顯示小數點（由decimal參數決定）
  if (decimal) 
  {
    // 如果decimal為true，將小數點（第8段，索引為7）設為HIGH以點亮它
    digitalWrite(seg7_a + 7, HIGH); 
  }
}


// 主循環函數
void loop()
{
  int x;  // 儲存將要顯示的整數
  int d;  // 儲存將要在單個七段顯示器上顯示的數字
  
  // 先關閉所有七段顯示器
  hide_seg7();
  
  // 從0000遞增到9999
  for (int x1 = 0; x1 < 10000; x1++) 
  {
    t0 = millis();  // 獲取當前時間
    
    // 等待100毫秒
    while (millis() - t0 < 100) 
    {
      x = x1;  // 更新將要顯示的數字
      
      // 以下四個區塊是用於顯示千位、百位、十位和個位
      d = x / 1000;  // 獲取千位數字
      show(seg7_digit[d]);  // 顯示千位數字
      digitalWrite(digits[0], LOW);  // 打開對應的共陰極
      delay(5);  // 等待5毫秒
      digitalWrite(digits[0], HIGH);  // 關閉共陰極

      x = x % 1000;  // 取餘數以獲取後三位
      d = x / 100;  // 獲取百位數字
      show(seg7_digit[d]);  // 顯示百位數字
      digitalWrite(digits[1], LOW);  // 打開對應的共陰極
      delay(5);  // 等待5毫秒
      digitalWrite(digits[1], HIGH);  // 關閉共陰極

      x = x % 100;  // 取餘數以獲取後兩位
      d = x / 10;  // 獲取十位數字
      show(seg7_digit[d]);  // 顯示十位數字
      digitalWrite(digits[2], LOW);  // 打開對應的共陰極
      delay(5);  // 等待5毫秒
      digitalWrite(digits[2], HIGH);  // 關閉共陰極

      x = x % 10;  // 取餘數以獲取個位
      d = x;  // 獲取個位數字
      show(seg7_digit[d], true);  // 顯示個位數字和小數點
      digitalWrite(digits[3], LOW);  // 打開對應的共陰極
      delay(5);  // 等待5毫秒
      digitalWrite(digits[3], HIGH);  // 關閉共陰極
    }
  }
}
