#define V1 "M="  // 定義一個巨集V1，用來儲存字串"M="
const int V2=22;  // 宣告一個整數常數V2，值為22
int M;  // 宣告一個整數變數M
int c[7]={6,1,1,5,1,1,1};  // 宣告一個整數數組c，包含7個元素
//如果用int ,c的位置會是0,2,4,6,8,10
//如果用char,c的位置會是0,1,2,3,4,5
int a=10;  // 宣告一個整數變數a，值為10
int b=20;  // 宣告一個整數變數b，值為20
int *p;  // 宣告一個指向整數的指針p


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  const int V3=33;
  M=V2+V3;
  //V2=100;//不能這樣打
  Serial.print("HELLO,M=");Serial.print(V1); Serial.println(M);
  Serial.print("c=");Serial.println((long)c, HEX);// 輸出數組c的地址（以十六進制形式）
  Serial.print("c[0] addr =");Serial.println((long)&c[0], HEX);//尋找c的初始位置

  // 輸出數組c的各個元素的地址（以十六進制形式）
  Serial.print("c[1] =");Serial.println((long)&c[1], HEX);//尋找c的第二個位置
  Serial.print("c[2] =");Serial.println((long)&c[2], HEX);//尋找c的第三個位置
  Serial.print("c[3] =");Serial.println((long)&c[3], HEX);//尋找c的第四個位置
  Serial.print("c[4] =");Serial.println((long)&c[4], HEX);//尋找c的第五個位置

  for(int i=0; i<7; i++) // 使用for迴圈遍歷數組c，並輸出對應數量的'#'
  {
    for(int j=0; j<c[i]; j++)
    {
      Serial.print("#");
    }
    Serial.println("");
  }
  

  p = c; // 將指針p指向數組c的首地址
  Serial.print("p=");Serial.print((long)p, HEX);
  Serial.print("[p]=");Serial.print(*p);//和37行一起看,意思是找到c的初始位置,並給p

  Serial.print("c addr =");Serial.println((long)p, HEX);//使用p去找c的初始位置
  Serial.print("a addr =");Serial.println((long)&a, HEX);//使用p去找a的初始位置
  Serial.print("b addr =");Serial.println((long)&b, HEX);//使用p去找b的初始位置
  Serial.print("[p] =");Serial.println((*p));//C的第一個數,就是6
  Serial.print("[p-1] =");Serial.println(*(p-1));//C的前一個數,是a,a的數是10
  Serial.print("[p+1] =");Serial.println(*(p+1));//C的第二個數,就是1
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("HELLO");//會跑無限次
}
