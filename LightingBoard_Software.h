// Lighting Board Software//////////////////////////////////////////////////////////////
	// Header file
//
// .h file holds constants and function declarations 
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
//
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
#define LED_COUNT         240//104 is number of pixels inside rover //136 is num of pixels on bottom of rover //240 pixels total
#define LED_SPI_MODULE    3 //PF_1
const neoPixelType NEOPIXEL_TYPE = NEO_GRB;

	//Software Variables
#define FREQ 			  0.7

	//Delays
#define ROVECOMM_DELAY    5

// Function Declarations ////////////////////////////////////////////////////////////////////////////////
void lightingSetup();
void lightingLoop(rovecomm_packet packet, RoveCommEthernetUdp * RoveComm);

#endif