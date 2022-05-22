/*
 * temp(c)  mv
 * 100      1600
 * 85       1450
 * 25       850
 * 0        600
 * -25      350
 * -30      300
 */

float LM61CIZ(){  
  float analog;
  analog = analogRead(LM61CIZPin);
  return analog;
}
