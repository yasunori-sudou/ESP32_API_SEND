#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "elecom2g-5edc39";
const char* password =  "b0Io3ogmbfkq";
//const String endpoint = "http://192.168.2.105/nfsys/api_receive/receive/receive/api_receve.php?token=jtkoaeuja";
const String endpoint = "http://192.168.2.105/nfsys/api_receive/receive/receive/api_receve_loadcell_temp_power.php?token=jtkoaeuja";


void api_setup(){
  pinMode(WIFI_POWER_LED,OUTPUT);  
  WiFi.begin(ssid, password);
  int ipcnt = 0; 
  while(WiFi.status() != WL_CONNECTED){
    delay(2000);
    Serial.println("Connecting to WiFi..");
    ipcnt += 1; 
    L_tika(2);
    if(ipcnt > 6){
      ESP.restart();//接続に6回失敗したらリセット
    }
    digitalWrite(WIFI_POWER_LED,LOW);
  }

  L_tika(5);
  Serial.println("Connected to the WiFi network");
  digitalWrite(WIFI_POWER_LED,HIGH);
  delay(1000);
}
 
void api_send(long val1,float val2,float val3){
  if((WiFi.status() == WL_CONNECTED)){
    HTTPClient http;
    /*---------API送信URL作成--------*/
    String key1 = "&val1=" + String(val1);
    String key2 = "&val2=" + String(val2);
    String key3 = "&val3=" + String(val3);
    http.begin(endpoint + key1 + key2 + key3); //URLを指定
    Serial.println(endpoint + key1 + key2 + key3);
    /*------------API送信-----------*/
    int httpCode = http.GET();  //GETリクエストを送信
    
    if(httpCode > 0){ 
        /*---------返答がある場合--------*/
        String payload = http.getString();  //返答（JSON形式）を取得
        Serial.println(payload);
    }else{
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
}
