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
#include "Adafruit_NeoPixel.h"

//Defining Hardware Variables
const byte LED_COUNT             = 12;
const byte LED_SPI_MODULE        = 3;//PF_1
const neoPixelType NEOPIXEL_TYPE = NEO_GRB;

//Define Software Variables
const int FREQ=1;
int count = 0, ledNum = 0, waitTime = 20, cursorWidth = 3;
bool track = 0, ledState=1;
uint8_t program; 

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);

struct rovecomm_packet packet; //RoveComm read sends struct

uint8_t NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_DATACOUNT];

void setup()
{
  Serial.begin(9600);
  NeoPixel.begin();
  RoveComm.begin(RC_LIGHTINGSHIMBLEBOARD_FOURTHOCTET); //sets the fourth octet of the ip address for networking with the Rover network
  delay(ROVECOMM_DELAY);// sets 5ms delay so code doesnt trip over itself

  pinMode(HEADLIGHT1_PIN, OUTPUT);
  //pinMode(HEADLIGHT2_PIN, OUTPUT);

  analogWrite(HEADLIGHT1_PIN, 0);
  //analogWrite(HEADLIGHT2_PIN, 0);

  //Makes Sure the LEDs are on
  NeoPixel.setBrightness(255);
   
  Serial.println("Setup Complete.");
}

  
void loop() 
{
  delay(10);
  packet = RoveComm.read(); //reads whats sent from RED

  if(packet.data_id != 0)
  {
    Serial.print("Data ID: ");
    Serial.println(packet.data_id);
    switch(packet.data_id)
    {
      case RC_LIGHTINGBOARD_SETLEDINTENS_DATAID:
      {
        uint8_t headlight_intensity = map(packet.data[0], 0, 100, 0, 255); //maps headlight intensity to 0-100 since 0-255 is jank apparently
        analogWrite(HEADLIGHT1_PIN, headlight_intensity); //turn the intensity to sent the data
      }
      case RC_LIGHTINGBOARD_SETRGB_DATAID:
      {
         Serial.print(packet.data[0]);
          Serial.print(packet.data[1]);
        Serial.println(packet.data[2]);
        NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_REDENTRY]   = packet.data[0];
        NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_GREENENTRY] = packet.data[1];
        NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_BLUEENTRY]  = packet.data[2];
      }
      case RC_LIGHTINGBOARD_LEDCMND_DATAID:
      {
        //packet.data[0] = program;
      }
    }
  }
  switch (program)
  {
  
    //Single direction RGB wave
    case 0:
      count ++;
      NeoPixel.setPixelColor(ledNum , NeoPixel.sine8(count/FREQ), NeoPixel.sine8((count/FREQ)+85), NeoPixel.sine8((count/FREQ)+170));
      if (ledNum<=LED_COUNT)
      {
        ledNum++;
      }
      else
      {
        ledNum=0;
      }
      delay(waitTime);
      break;
    
    //RGB wave bounce
    case 1:
      count ++;
      NeoPixel.setPixelColor(ledNum , NeoPixel.sine8(count/FREQ), NeoPixel.sine8((count/FREQ)+85), NeoPixel.sine8((count/FREQ)+170));
      if (track==0)
      {
        NeoPixel.setPixelColor(ledNum , NeoPixel.sine8(count/FREQ), NeoPixel.sine8((count/FREQ)+85), NeoPixel.sine8((count/FREQ)+170));
        if (ledNum<=(LED_COUNT))
        {
          ledNum++;
        }
        else
        {
          track=1;
        }
      }
      else if (track=1)
      {
        NeoPixel.setPixelColor(ledNum , NeoPixel.sine8(count/FREQ), NeoPixel.sine8((count/FREQ)+85), NeoPixel.sine8((count/FREQ)+170));
        if (ledNum>=0)
        {
          ledNum--;
        }
        else
        {
          track=0;
        }
      }
      delay(waitTime);
      break;
    
    //White cursor with red/blue sides
    case 2:
      count ++;
      if (track==0)
      {
        NeoPixel.setPixelColor(ledNum , 255, 255, 255);
        NeoPixel.setPixelColor((ledNum-cursorWidth), 255, 0, 0);
        if (ledNum<=(LED_COUNT-2))
        {
          ledNum++;
        }
        else
        {
          track=1;
        }
      }
      else if (track=1)
      {
        NeoPixel.setPixelColor(ledNum , 255, 255, 255);
        NeoPixel.setPixelColor((ledNum+cursorWidth), 0, 0, 255);
        if (ledNum>=1)
        {
          ledNum--;
        }
        else
        {
          track=0;
        }
      }
      delay(waitTime);
      break;
      
  }
  
  if (ledState==1)  
    NeoPixel.show();
}
