//const int POWERPIN = 36;//SENSER_VP
//const int TRIGGERPIN = 25;

void POWER_setup() {
  pinMode(TRIGGERPIN,OUTPUT);
  digitalWrite(TRIGGERPIN,LOW);
}

float Power_Measurement(){
  float volt;
  digitalWrite(TRIGGERPIN,HIGH);
  delay(500);
  volt = analogRead(POWERPIN);
  digitalWrite(TRIGGERPIN,LOW);
  return volt;
}
