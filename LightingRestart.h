// Libraries ////////////////////////////////////////////////////////////////////////////
#ifndef _LightingBoard
#define _LightingBoard

#include <Energia.h> 
#include "RoveComm.h"
#include "Adafruit_NeoPixel.h"

// Constants //////////////////////////////////////////////////////////////////////////////
	//Pinout
#define HEADLIGHT1_PIN    PD_0  ///Headlight_OnOff_PWM1
#define NEOPIXEL_PIN      PF_1  ///Dout_NeoPixel 

	//Hardware Variables
#define LED_COUNT         104//104 is number of pixels inside rover //136 is num of pixels on bottom of rover //240 pixels total
#define LED_SPI_MODULE    3 //PF_1
const neoPixelType NEOPIXEL_TYPE = NEO_GRB;

	//Delays
#define ROVECOMM_DELAY    5

// Function Declarations ////////////////////////////////////////////////////////////////////////////////
void lightingRestartSetup();
void lightingRestartLoop(rovecomm_packet packet, RoveCommEthernetUdp * RoveComm);

#endif