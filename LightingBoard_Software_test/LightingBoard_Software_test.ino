//Ryan Nachtmann's NeoPixel code that probably works

//Including the NeoPixel Library
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

/////////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{  
  rovecomm_packet= RoveComm.read(); //reads whats sent from RED

  if(rovecomm_packet.data_id != 0)
  {
    switch(rovecomm_packet.data_id)
    {
      case RC_LIGHTINGBOARD_SETLEDINTENS_DATAID:
      {
        uint8_t headlight_intensity = map(rovecomm_packet.data[0], 0, 100, 0, 255); //maps headlight intensity to 0-100 since 0-255 is jank apparently
        analogWrite(HEADLIGHT1_PIN, headlight_intensity); //turn the intensity to sent the data
      }
      case RC_LIGHTINGBOARD_SETRGB_DATAID:
      {
         
        analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_REDENTRY]);
        analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_GREENENTRY]);
        analogWrite( NeoPixel, NeoPixelRGB[RC_LIGHTINGBOARD_SETRGB_BLUEENTRY]);
      }
      case RC_LIGHTINGBOARD_LEDCMND_DATAID:
      {
        rovecomm_packet.data[0] = program;
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
