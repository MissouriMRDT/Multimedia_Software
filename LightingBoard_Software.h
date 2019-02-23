// Lighting Board Software//////////////////////////////////////////////////////////////
    // Header file
//
// .h file holds constants and function declarations 
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
//
// Libraries ////////////////////////////////////////////////////////////////////////////

#include <Energia.h> 
#include "RoveComm.h"
#include "Adafruit_NeoPixel.h"

RoveCommEthernetUdp RoveComm; // extantiates a class (object)

// Constants //////////////////////////////////////////////////////////////////////////////
	//Pinout
#define HEADLIGHT1_PIN    PD_0  ///Headlight_OnOff_PWM1
#define NEOPIXEL_PIN      PF_1  ///Dout_NeoPixel 

	//Hardware Variables
#define LED_COUNT         12
#define LED_SPI_MODULE    3 //PF_1
const neoPixelType NEOPIXEL_TYPE = NEO_GRB;

	//Software Variables
#define FREQ 			  1
	
	//Delays
#define ROVECOMM_DELAY    5

// Function Declarations ////////////////////////////////////////////////////////////////////////////////
void lightingSetup();
void lightingLoop();

