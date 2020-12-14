#include <SimpleSDAudio.h>
#include <stdint.h>
#include "TouchScreen.h"

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 7   // can be a digital pin
// X-, Y+, X+, Y-

#define B1 = 3
#define B2 = 4
#define B3 = 5
#define B4 = 6

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() 
{

  SdPlay.setSDCSPin(10); // sd card cs/ss pin

  // Detect SD card connection
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  { 
    while(1); 
  }
  else {
    Serial.print("Y");
  }
  Serial.begin(9600);
}


void loop(void)
{

  int value = analogRead(A1);

  // Multiplexing (Main tap pads)
  if (value >= 0 && value < 100) {
    SdPlay.setFile("m1.wav");
    SdPlay.play();
    
  } else if (value >= 500 && value < 520) {
    SdPlay.setFile("m2.wav");
    SdPlay.play();
    
  } else if (value >= 660 && value < 700) {
    SdPlay.setFile("m4.wav");
    SdPlay.play();
    
  } else if (value >= 760 && value < 780) {
    SdPlay.setFile("m7.wav");
    SdPlay.play();
    
  } else if (value >= 810 && value < 830) {
    SdPlay.setFile("m10.wav");
    SdPlay.play();
    
  } else if (value >= 840 && value < 870) {
    SdPlay.setFile("m11.wav");
    SdPlay.play();
  } 
  

  Serial.print(digitalRead(A2));
  
  if (digitalRead(B1) == LOW) {
    SdPlay.setFile("ms1.wav");
    SdPlay.play();
  }

  if (digitalRead(B2) == LOW) {
    SdPlay.setFile("ms2.wav");
    SdPlay.play();
  }

  if (digitalRead(B3) == LOW) {
    SdPlay.setFile("ms3.wav");
    SdPlay.play();
  }

  if (digitalRead(B4) == LOW) {
    SdPlay.setFile("ms4.wav");
    SdPlay.play();
  }

  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
  
    // bottom right
    if (p.x > 500 && p.y < 450) {
      Serial.println("1 pressed \n");
      SdPlay.setFile("ms5.wav");
      SdPlay.play();
    }
    // top right
    if (p.x < 500 && p.y < 450) {
      Serial.println("2 pressed \n");
      SdPlay.setFile("ms6.wav");
      SdPlay.play();
    }
    // bottom left
    if (p.x > 500 && p.y > 450) {
      Serial.println("3 pressed \n");
      SdPlay.setFile("ms7.wav");
      SdPlay.play();
    }
    // top left
    if (p.x < 500 && p.y > 450) {
      Serial.println("4 pressed \n");
      SdPlay.setFile("ms8.wav");
      SdPlay.play();
    }
  }
  
  delay(200);

}
