#include "n64ykr.h"

#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();

void setup() {
  // put your setup code here, to run once:
tft.init();
  tft.setRotation(5);

  tft.setSwapBytes(true);
  tft.fillScreen(TFT_BLACK);
  
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<frames;i++)

{
  delay(100);
  tft.pushImage(29, 29,animation_width  , animation_height, n64ykr[i]);
  
  }

}
