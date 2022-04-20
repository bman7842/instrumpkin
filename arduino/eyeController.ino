//See https://wiki.keyestudio.com/KS0454_keyestudio_Circular_TFT_LCD_Smart_Watch_Display_Module for documentation

#include "DFRobot_ST7687S_Latch.h"

#ifdef __AVR__
uint8_t pin_cs = 3, pin_rs = 5, pin_wr = 6, pin_lck = 7;
#else
uint8_t pin_cs = D3, pin_rs = D5, pin_wr = D6, pin_lck = D7;
#endif

DFRobot_ST7687S_Latch tft(pin_cs, pin_rs, pin_wr, pin_lck);

#define eye_color DISPLAY_BLACK
#define eye_socket_radius 50

int prevRadius, radius, prevX, x, prevY, y;

void setup(void)
{
  radius = 25;
  x = 0;
  y = 0;
  
  tft.begin();
  tft.fillScreen(DISPLAY_BLACK);
  tft.fillCircle(0, 0, eye_socket_radius, DISPLAY_WHITE);
  Serial.begin(115200);
}

//Data is received as radius, x pos, y pos, update accordingly
//Origin is middle of screen (0,0), can move -64-64 either axis
void loop(void)
{
  if (Serial.available()) {
    radius = Serial.read();
    x = Serial.read()-64;//Data sent will be 0-128, converts to -64-64
    y = Serial.read()-64;
    
    if (Serial.available()){
      while (Serial.available() > 0) { 
          int junk = Serial.read(); 
        }
    }
    Serial.println(0);
  }

  if ((radius != prevRadius) or (x != prevX) or (y != prevY)) {
     clearEye();
     generateEye();
   }

   delay(100);
}

void clearEye() {
  tft.fillCircle(0, 0, eye_socket_radius, DISPLAY_WHITE);
}

void generateEye() {
  tft.fillCircle(x, y, radius, DISPLAY_BLACK);
  prevRadius = radius;
  prevX = x;
  prevY = y;
}

//draw outer eyeball, black. It should never be redrawn after setup for efficiency
//Store previous data for eye, that way you only have to make it white, not the whole screen (efficiency)
