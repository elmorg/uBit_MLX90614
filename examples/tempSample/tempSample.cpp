/*********************************************************************** 
  Example code for the uBit_MLX90614 library.
  
  When button A is pressed, the microbit samples and displays the object
  temperature.
  
  Written by Evan Morgan, School of Informatics, University of Edinburgh 
  Distributed under the MIT Licence - https://opensource.org/licenses/MIT
  Copyright (c) 2016 University of Edinburgh
 *************************************************************************/

#include "MicroBit.h"
#include "uBit_MLX90614.h"

MicroBit uBit;
uBit_MLX90614 IRtemp = uBit_MLX90614(&uBit.i2c);

int tempAmbient = 0;
float tempObject = 0;
float br = 0;
float in_min = 26.0;
float in_max = 32.0;

MicroBitDisplay display;  

void onButtonA(MicroBitEvent e)
{
    MicroBitImage i("255,255,0,0,0\n255,255,0,0,0\n0,0,255,255,255\n0,0,255,0,0\n0,0,255,255,255\n");
    tempObject = (float)IRtemp.getObject()/100.0;  
    uBit.display.print((int) tempObject);
    uBit.display.print(i);
    wait(1);
    uBit.display.clear();
}

int main()
{
    uBit.init();
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
    uBit.display.setBrightness(255);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    // We don't want to drop out of main!
    while(1)
        uBit.sleep(100);
}