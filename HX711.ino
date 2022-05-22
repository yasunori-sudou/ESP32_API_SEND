//const int DT_PIN = 32;
//const int SCK_PIN = 33;
float offset = 0;//誤差調整用

void HX711_setup() {
  pinMode(SCK_PIN, OUTPUT);
  pinMode(DT_PIN, INPUT);
}

long HX711(){
  long val = 0;
  float gram = 0;
  
  do{
    val = HX711data();
    delay(100);
  } while(val < 850000);//異常値838607をカット
  /*--------取得値をgramに変換---------*/
  gram = val;
  return val;
}
long HX711data(){
  long val = 0;
  for(char j = 0; j < 24; j++){
    digitalWrite(SCK_PIN, 1);
    delayMicroseconds(1);
    digitalWrite(SCK_PIN, 0);
    delayMicroseconds(1);
    val = (val << 1) | (digitalRead(DT_PIN));
  }
  val = val ^ 0x800000;   
  return val;
}
