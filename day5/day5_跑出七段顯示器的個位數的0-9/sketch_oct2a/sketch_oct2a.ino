// 定義7段顯示器的起始腳位為2
#define seg7_a 2

// 定義一個數組，儲存0~9在7段顯示器上的編碼
int seg7_digit[10]={0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe4, 0xfe, 0xf6};

// 定義一個數組，儲存4個7段顯示器的公共腳位
int digits[4]={10,11,12,13};

void setup() {
  // 初始化程式

  // 初始化7段顯示器的各個段（a-g及小數點）的腳位為輸出模式
  for(int i=0; i<8; i++)
  {
    pinMode(seg7_a+i, OUTPUT);
    digitalWrite(seg7_a+i, LOW); // 初始設置為LOW（不亮）
  }
  
  // 初始化4個7段顯示器的公共腳位為輸出模式
  for(int i=0; i<4; i++){
     pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH); // 初始設置為HIGH（不啟動該位數）
  }
  
  // 啟動最後一個7段顯示器（僅作為示例）
  digitalWrite(digits[3], LOW);
}

// 自定義函數，用於顯示單個數字（傳入對應的7段編碼）
void show(int val){
  int mask0 = B10000000; // 初始掩碼，用於與val進行位運算
  int mask; // 當前掩碼
  
  // 循環遍歷每一個段（a-g及小數點）
  for(int i=0; i<8; i++){
    mask = mask0 >> i; // 右移掩碼以配合當前段
    if(val&mask) digitalWrite(seg7_a+i, HIGH); // 若對應位為1，則該段亮
    else digitalWrite(seg7_a+i, LOW); // 若對應位為0，則該段熄
  }
}

void loop() {
  // 主循環

  // 循環遍歷0-9，並在7段顯示器上顯示
  for(int i=0; i<10; i++){
    show(seg7_digit[i]); // 顯示對應的數字
    delay(1000); // 每顯示一個數字後延遲1000毫秒（1秒）
  }
}

// 程式結束
