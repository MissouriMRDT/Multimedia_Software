// Libraries //////////////////////////////////////////////////////////////////////////////////////

#include "LightingBoard_Software.h"
#include "RoveComm.h"

//Define Software Variables
uint8_t count = 0, ledNum = 0, waitTime = 20, cursorWidth = 3;
//bool track = 0, ledState=1;
uint8_t program; 

//Instantiating NeoPixel Class based on Hardware Variables
Adafruit_NeoPixel   NeoPixel(LED_COUNT, LED_SPI_MODULE, NEOPIXEL_TYPE);

uint8_t NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_DATACOUNT];

// Setup & Loop Funcitons //////////////////////////////////////////////////////////////////////////////

void lightingSetup()
{
  Serial.begin(9600);
  NeoPixel.begin();

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
    }
  }
}