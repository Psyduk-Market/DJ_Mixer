// Tested with 2 buttons 24/09/2020
// Button displayed was 4 and 5

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A1);
  
  if (value >= 0 && value < 500) {
    Serial.println("Button1");
  } else if (value >= 500 && value < 650) {
    Serial.println("Button2");
  } else if (value >= 650 && value < 750) {
    Serial.println("Button3");
  } else if (value >= 750 && value < 800) {
    Serial.println("Button4");
  } else if (value >= 800 && value < 840) {
    Serial.println("Button5");
  } else if (value >= 840 && value < 865) {
    Serial.println("Button6");
  } else if (value >= 865 && value < 885) {
    Serial.println("Button7");
  } else if (value >= 885 && value < 900) {
    Serial.println("Button8");
  } else if (value >= 900 && value < 920) {
    Serial.println("Button9");
  }
//  Serial.println(value);
  delay(500);
}
