
/*----------Lチカ用LED----------*/
const int LED_1 = 27;
/*----------Wi-Fi用LEDピン----------*/
const int WIFI_POWER_LED = 14;
/*----------HX711用ピン----------*/
const int DT_PIN = 32;
const int SCK_PIN = 33;
/*----------電源測定用ピン----------*/
const int POWERPIN = 36;//SENSER_VP
const int TRIGGERPIN = 25;
/*----------LM61CIZPin用ピン----------*/
const int LM61CIZPin = 39;//SENSER_VN
/*--------------------*/
const int setminute = 1;//DeepSleepの待機時間(分)

void setup() {
  Serial.begin(115200);
  api_setup();
  HX711_setup();
  POWER_setup();
  pinMode(LED_1,OUTPUT);
  /*----------DeepSleep中の設定----------*/
  esp_sleep_enable_timer_wakeup(((setminute * 60) - 6) * 1000 * 1000);//wakeup every secs
  /*-----------------------------------*/
}

void loop() {
  long glam;
  float temp;
  float power;
  glam = HX711();
  temp = LM61CIZ();
  power = Power_Measurement();
  
  Serial.print("gram=");
  Serial.print(glam);
  Serial.print(",temp=");
  Serial.print(temp);
  Serial.print(",power=");
  Serial.println(power);
  delay(200);
  api_send(glam,temp,power);
  L_tika(2);
  esp_deep_sleep_start(); 
}

/*----------Lチカ関数----------*/
void L_tika(int cnt){
  for(int i=0;i<cnt;i++){
    digitalWrite(LED_1,HIGH);
    delay(100);
    digitalWrite(LED_1,LOW);
    delay(100);
  }
}
