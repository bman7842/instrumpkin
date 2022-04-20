#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ORANGE  0xFB60

#define fill_color BLACK
#define background_color ORANGE
//the definiens of 16bit mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV mylcd(ILI9486,40,38,39,-1,41); //model,cs,cd,wr,rd,reset

int mouthWidth;
int mouthHeight;
int currentMouthWidth;
int currentMouthHeight;
int rateOfChange;

void setup() 
{
  mouthWidth = 5;
  mouthHeight = 400;
  rateOfChange = 0;
  currentMouthWidth = mouthWidth;
  currentMouthHeight = mouthHeight;
  
  Serial.begin(115200);
  mylcd.Init_LCD();

  mylcd.Fill_Screen(background_color);
  generateFace();
}

void loop() {
  if (Serial.available()) {  
    mouthWidth = Serial.read()+Serial.read();
    mouthHeight = Serial.read()+Serial.read();

    if (Serial.available()){
      while (Serial.available() > 0) { 
          int junk = Serial.read(); 
        }
      Serial.println(0);
    }
  }
  
  if (adjustCurrentValues()){
    mylcd.Fill_Screen(background_color);
    generateFace();
  }
  delay(30);
}

void generateFace()
{
  mylcd.Set_Draw_color(fill_color);
  
  int radius = currentMouthWidth/2;
  int rectangleWidth = currentMouthWidth;
  int rectangleHeight = currentMouthHeight-(2*radius);
  int horizontalSpacer = (mylcd.Get_Display_Width()-rectangleWidth)/2;
  int verticalSpacer = (mylcd.Get_Display_Height()-rectangleHeight)/2;
  
  mylcd.Fill_Circle(mylcd.Get_Display_Width()/2, verticalSpacer, radius);
  mylcd.Fill_Circle(mylcd.Get_Display_Width()/2, verticalSpacer+rectangleHeight, radius);
  mylcd.Fill_Rectangle(horizontalSpacer,verticalSpacer,horizontalSpacer+rectangleWidth,verticalSpacer+rectangleHeight);
}

//Returns true if values need adjusting
bool adjustCurrentValues() {
  bool changeNeeded = false;
  if (mouthWidth != currentMouthWidth) {
    currentMouthWidth = mouthWidth; //temp
    changeNeeded = true;
  }
  
  if (mouthHeight != currentMouthHeight) {
    currentMouthHeight = mouthHeight; //temp
    changeNeeded = true;
  }
  return changeNeeded;
}
