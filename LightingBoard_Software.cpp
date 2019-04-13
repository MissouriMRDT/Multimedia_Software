// Lighting Board Software/////////////////////////////////////////////////////////////////////////
    // Main Header file
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
//
// Libraries //////////////////////////////////////////////////////////////////////////////////////

#include "LightingBoard_Software.h"
#include "RoveComm.h"

//Define Software Variables
uint8_t count = 0, ledNum = 0, waitTime = 20, cursorWidth = 3;
bool track = 0, ledState=1;
uint8_t program; 

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);

uint8_t NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_DATACOUNT];

// Setup & Loop Funcitons //////////////////////////////////////////////////////////////////////////////

void lightingSetup()
{
  Serial.begin(9600);
  NeoPixel.begin();

  pinMode(HEADLIGHT1_PIN, OUTPUT);

  analogWrite(HEADLIGHT1_PIN, 0);

  NeoPixel.setBrightness(0);//Makes Sure the LEDs are off
   
  Serial.println("Lighting Setup Complete.");
}

  
void lightingLoop(rovecomm_packet packet, RoveCommEthernetUdp * RoveComm) 
{
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
        break;
      }
      case RC_LIGHTINGBOARD_SETRGB_DATAID:
      {
        NeoPixel.clear(); // Set all pixel colors to 'off'
        NeoPixel.setBrightness(70);
        program = 0;

        Serial.print(packet.data[0]);
        Serial.print(packet.data[1]);
        Serial.println(packet.data[2]);

        for (int i=0; i < LED_COUNT; i++)
        {
          Serial.println("Inside For()");
          NeoPixel.setPixelColor(i, packet.data[0], packet.data[1], packet.data[2]);
          NeoPixel.show();
          delay(25);
        }
        Serial.println("Left For()");
        break;
      }
      case RC_LIGHTINGBOARD_LEDCMND_DATAID:
      {
        program = packet.data[0];
        Serial.println(packet.data[0]);
        break;
      }
    }
  }

  switch (program)
  {
  
    //Single direction RGB wave
    case 1:
      Serial.println("YUM");
      NeoPixel.setBrightness(70);
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
    case 2:
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
    case 3:
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
  
  if (ledState == 1) 
  {
    NeoPixel.show();
  } 
}
