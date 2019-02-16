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


void setup()
{
  Serial.begin(9600);
  //RoveComm.begin(RC_LIGHTINGSHIMBLEBOARD_FOURTHOCTET); //sets the fourth octet of the ip address for networking with the Rover network
  //delay  (ROVECOMM_DELAY);                      // sets 10ms delay so code doesnt trip over itself

  pinMode(HEADLIGHT1_PIN, OUTPUT);
  //pinMode(HEADLIGHT2_PIN, OUTPUT);
  Serial.println("Setup Complete.");
}

  
void loop() 
{

  delay(100);
  analogWrite(HEADLIGHT1_PIN, 0);
  analogWrite(HEADLIGHT2_PIN, 100);
  
}
