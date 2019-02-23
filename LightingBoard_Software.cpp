// Lighting Board Software/////////////////////////////////////////////////////////////////////////
    // Main Header file
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
//
// Libraries //////////////////////////////////////////////////////////////////////////////////////

#include "LightingBoard_Software_Main.h"

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);

struct rovecomm_packet rovecomm_packet; //RoveComm read sends struct


int count = 0;

void setup()
{
  Serial.begin(9600);
  NeoPixel.begin();
  RoveComm.begin(RC_LIGHTINGSHIMBLEBOARD_FOURTHOCTET); //sets the fourth octet of the ip address for networking with the Rover network
  
  delay(ROVECOMM_DELAY);                      // sets 10ms delay so code doesnt trip over itself

  pinMode(HEADLIGHT1_PIN, OUTPUT);
  pinMode(HEADLIGHT2_PIN, OUTPUT);

  analogWrite(HEADLIGHT1_PIN, 0);
  analogWrite(HEADLIGHT2_PIN, 0);

  NeoPixel.setBrightness(255);
   
  Serial.println("Setup Complete.");
}

  
void loop() 
{
  rovecomm_packet= RoveComm.read(); //reads whats sent from rover

  
  if(rovecomm_packet.data_id == RC_LIGHTINGBOARD_SETRGB_DATAID)
  {
    uint8_t NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_DATACOUNT]; 
    analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_REDENTRY]);
    analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_GREENENTRY]);
    analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_BLUEENTRY]);
  }

  
  if(rovecomm_packet.data_id == RC_LIGHTINGBOARD_SETLEDINTENS_DATAID) //if rover sends stuff to this board
  {
    uint8_t intensity = map(rovecomm_packet.data[0], 0, 100, 0, 255); //maps headlight intensity to 0-100 since 0-255 is jank apparently
    analogWrite(HEADLIGHT1_PIN, intensity); //turn the intensity to sent the data
  }
  
  if (rovecomm_packet.data_id==RC_LIGHTINGBOARD_LEDCMND_DATAID)
  {
    uint8_t 
  }
  //analogWrite(HEADLIGHT1_PIN, 127);
  //analogWrite(HEADLIGHT2_PIN, 127);

   for(count; count < NeoPixel.numPixels(); count++)
   {
    NeoPixel.setPixelColor(count, 255, 0, 0);
   }
}
