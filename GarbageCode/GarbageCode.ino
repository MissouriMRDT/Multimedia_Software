/*
 * DriveBoard Software Rev 2 2018
 * Used with DriveBoard Rev 2 2018
 * Writes Serial to 6 motor controllers, controls RGB LD strips, Headlights, and 4 Dropbay Servos
 * 
 * Andrew Van Horn, Judah Schad
 * Disclaimer- I know this code is jank. The servo libraries were giving me trouble at competition, and this conficguration somehow worked. Give me a break
 */

//Including the NeoPixel Library
#include "Adafruit_NeoPixel.h"


//Defining Hardware Variables
const byte LED_COUNT             = 3;
const byte LED_SPI_MODULE        = 3;//PF_1
const neoPixelType NEOPIXEL_TYPE = NEO_GRB;

//Define Software Variables
int count = 0;

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);
/////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  
  NeoPixel.begin();
  delay(1);
  //Not Necesary for code, useful for debugging
  //Serial.begin(9600);
  //delay(1);
  //Serial.println("Initialized");

  //Makes Sure the LEDs are on
  NeoPixel.setBrightness(255);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{  

  //Sets a single LED to an RGB Value(LED number, Red Value[0-255], Green Value[0-255], Blue Value[0-255])

  /*
  NeoPixel.setPixelColor(0, 255, 0, 0); //Sets pixel 1 to Red
  NeoPixel.setPixelColor(1, 0, 255, 0); //Sets pixel 2 to Green
  NeoPixel.setPixelColor(2, 0, 0, 255); //Sets pixel 3 to Blue
   */


   //sets all LEDs to Red
   for(uint8_t i = 0; i<NeoPixel.numPixels(); i++)
   {
    NeoPixel.setPixelColor(i, 255, 0, 0);
   }
   

   //Ramps LED
  
   count ++;
   if(count > 2550) count = 0;
   NeoPixel.setPixelColor(0, count/10, 0, 0);
   NeoPixel.setPixelColor(1,0,count/10,0);
   NeoPixel.setPixelColor(2,0,0,count/10);
 
  /*
  int fghj=1;
count ++;
if(count>2550) count=0;{

NeoPixel.setPixelColor(0+fghj, count*10, 0, 0);
NeoPixel.setPixelColor(1+fghj, 0, count*10, count*10);
}

else{
NeoPixel.setPixelColor(0, count*10, 0, 0);
}
*/


//Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE)
   //Sine Wave LED
   
/*   count ++;
   if(count > 2550) count = 0;
   NeoPixel.setPixelColor(1, 0, NeoPixel.sine8(count/10), 0);


   //Gamma Wave LED
   /*
   count ++;
   if(count > 2550) count = 0;
   NeoPixel.setPixelColor(2, 0, 0, NeoPixel.gamma8(count/10));
   
   */
   
  
  
  NeoPixel.show();
}
