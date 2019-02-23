// Lighting Board Software//////////////////////////////////////////////////////////////
    // Main Header file
//
// .h file holds constants and function declarations 
//
// Created for 2019 Valkyrie by John Beuke, jrbyh6@mst.edu
////////////////////////////////////////////////////////////////////////////////////////
// This is the new and better code than the original jank code created by John Beuke
// This will intergrate headlight control with neopixels control to create "lighting board'
////2-15-2018////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#include <Energia.h> 
#include "RoveComm.h"
#include "Adafruit_NeoPixel.h"

RoveCommEthernetUdp RoveComm; // extantiates a class (object)

// Pinmap //////////////////////////////////////////////////////////////////////////////

#define HEADLIGHT1_PIN    PD_0  ///Headlight_OnOff_PWM1
#define HEADLIGHT2_PIN    PD_1  ///Headlight_OnOff_PWM2
#define NEOPIXEL_PIN      PF_1  ///Dout_NeoPixel 

//  Constants///////////////////////////////////////////////////////////////////////////
	//Delays
#define ROVECOMM_DELAY    			5    // sets delay to 5ms
	//NeoPixels
#define LED_COUNT            		3
#define LED_SPI_MODULE        		3 //PF_1
const neoPixelType NEOPIXEL_TYPE 	= NEO_GRB;
