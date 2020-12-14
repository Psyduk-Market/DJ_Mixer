#include <SimpleSDAudio.h>
#include <stdint.h>
#include "TouchScreen.h"

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3  // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 7   // can be a digital pin
// X-, Y+, X+, Y-

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() 
{

  SdPlay.setSDCSPin(10); // sd card cs/ss pin

  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
  { 
    while(1); 
  }
  else {
    Serial.print("Y");
//    SdPlay.setFile("m1.wav");
//    SdPlay.play();
    
  }
  
//  if(!SdPlay.setFile("m2.wav")) 
//  { 
//    while(1) 
//    {
//      
//    }
//  }
  Serial.begin(9600);

}

//Ranges from 1-100
//int volume = 100;
//int value;


//void volumeSet() {
//  value = analogRead(A0);
////  Serial.println(value);
//  volume = (value*100)/1023;
////  Serial.println(volume);
//}


//void playSound(void) {
//  bool hasNotStopped = true;
//  SdPlay.play();
//  while(hasNotStopped) {
//    SdPlay.pause();   // Not playing
//    delay(100-volume);
//    SdPlay.pause();   // Playing
//    delay(volume);
//    hasNotStopped = SdPlay.isPlaying();
////    volumeSet();
//    }
//}

void loop(void)
{

  int value = analogRead(A1);
  
  if (value >= 0 && value < 100) {
    Serial.println("Button1");
    Serial.println(value);
    SdPlay.setFile("m1.wav");
//    playSound();
    SdPlay.play();
    
  } else if (value >= 500 && value < 520) {
    Serial.println("Button2");
//    SdPlay.setFile(analogRead(A1));
//    Serial.println(value);
    SdPlay.setFile("m2.wav");
//    playSound();
    SdPlay.play();
    
  } else if (value >= 660 && value < 700) {
    Serial.println("Button3");
//    SdPlay.setFile(analogRead(A1));
    SdPlay.setFile("m4.wav");
//    Serial.println(value);
//    playSound();
    SdPlay.play();
    
  } else if (value >= 760 && value < 780) {
    Serial.println("Button4");
//    SdPlay.setFile(analogRead(A1));
    SdPlay.setFile("m7.wav");
//    Serial.println(value);
//    playSound();
    SdPlay.play();
    
  } else if (value >= 810 && value < 830) {
    Serial.println("Button5");
//    SdPlay.setFile(analogRead(A1));
    SdPlay.setFile("m10.wav");
//    Serial.println(value);
    SdPlay.play();
    
  } else if (value >= 840 && value < 870) {
    Serial.println("Button6");
//    SdPlay.setFile(analogRead(A1));
    SdPlay.setFile("m11.wav");
//    Serial.println(value);
    SdPlay.play();
    
  } 
  

  Serial.print(digitalRead(A2));
  
  if (digitalRead(6) == LOW) {
    Serial.println("B1 pressed \n");
    SdPlay.setFile("ms1.wav");
    SdPlay.play();
  }

  if (digitalRead(5) == LOW) {
    Serial.println("B2 pressed \n");
    SdPlay.setFile("ms2.wav");
    SdPlay.play();
  }

  if (digitalRead(4) == LOW) {
    Serial.println("B3 pressed \n");
//    Serial.println("Button9");
    SdPlay.setFile("ms3.wav");
    SdPlay.play();
  }

  if (digitalRead(3) == LOW) {
    Serial.println("B4 pressed \n");
    SdPlay.setFile("ms4.wav");
    SdPlay.play();
  }

//  Serial.print(digitalRead(A2) == HIGH);

//  SdPlay.play(); // play music
//  
//  while(!SdPlay.isStopped())
//  { 
//  
//  }

  TSPoint p = ts.getPoint();
  
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!
  if (p.z > ts.pressureThreshhold) {
//     Serial.print("X = "); Serial.print(p.x);
//     Serial.print("\tY = "); Serial.print(p.y);
//     Serial.print("\tPressure = "); Serial.println(p.z);
  
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
