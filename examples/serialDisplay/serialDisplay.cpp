/*********************************************************************** 
  Example code for the uBit_MLX90614 library.
  
  Gets object and ambient temperatures every second and displays them on
  a connected computer via serial.
  
  Written by Evan Morgan, School of Informatics, University of Edinburgh 
  Distributed under the MIT Licence - https://opensource.org/licenses/MIT
  Copyright (c) 2016 University of Edinburgh
 *************************************************************************/

#include "MicroBit.h"
#include "uBit_MLX90614.h"

MicroBit uBit;
uBit_MLX90614 IRtemp = uBit_MLX90614(&uBit.i2c);

int tempAmbient = 0;
int tempObject = 0;

int main() {
 uBit.init();
 Serial pc(USBTX, USBRX); // tx, rx
 while(1){
 tempObject = IRtemp.getObject();
 tempAmbient = IRtemp.getAmbient();
 pc.printf("Object = %d.%d C    Ambient = %d.%d \n\r",tempObject/100,tempObject%100,tempAmbient/100,tempAmbient%100);
 wait(1);
}
 release_fiber();
 return 0;
 }