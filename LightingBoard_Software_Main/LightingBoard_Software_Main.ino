// Lighting Board Software//////////////////////////////////////////////////////////////
    // Main Header file
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
////////////////////////////////////////////////////////////////////////////////////////
// This is the new and better code than the original jank code created by John Beuke
// This will intergrate headlight control with neopixels control to create "lighting board'
////2-15-2018////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#include "LightingBoard_Software_Main.h"

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);

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

  delay(10);

  analogWrite(HEADLIGHT1_PIN, 127);
  analogWrite(HEADLIGHT2_PIN, 127);

   for(count; count < NeoPixel.numPixels(); count++)
   {
    NeoPixel.setPixelColor(count, 255, 0, 0);
   }
}
