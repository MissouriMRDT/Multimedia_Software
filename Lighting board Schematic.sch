EESchema Schematic File Version 4
LIBS:Lighting board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MRDT_Shields:TM4C129E_Launchpad U?
U 2 1 5BCE41EC
P 7150 2850
F 0 "U?" H 6950 4000 60  0000 L CNN
F 1 "TM4C129E_Launchpad" H 6100 4200 60  0000 L CNN
F 2 "" H 7150 2850 60  0001 C CNN
F 3 "" H 7150 2850 60  0001 C CNN
	2    7150 2850
	1    0    0    -1  
$EndComp
Text GLabel 6950 1900 0    50   Input ~ 0
5V
$Comp
L MRDT_Shields:TM4C129E_Launchpad U?
U 3 1 5BCE44EF
P 5800 2900
F 0 "U?" H 5850 4050 60  0000 L CNN
F 1 "TM4C129E_Launchpad" H 6400 3600 60  0001 L CNN
F 2 "" H 5800 2900 60  0001 C CNN
F 3 "" H 5800 2900 60  0001 C CNN
	3    5800 2900
	-1   0    0    -1  
$EndComp
Text GLabel 6000 1950 2    50   Output ~ 0
Dout_NeoPixel1
$Comp
L MRDT_Shields:TM4C129E_Launchpad U?
U 4 1 5BCE45EC
P 5200 2900
F 0 "U?" H 5250 4050 60  0000 L CNN
F 1 "TM4C129E_Launchpad" H 5600 3500 60  0001 L CNN
F 2 "" H 5200 2900 60  0001 C CNN
F 3 "" H 5200 2900 60  0001 C CNN
	4    5200 2900
	1    0    0    -1  
$EndComp
Text GLabel 5000 1950 0    50   UnSpc ~ 0
GND
$Comp
L Device:C C
U 1 1 5BCE5020
P 9600 3950
F 0 "C" H 9715 3996 50  0000 L CNN
F 1 "10uF" H 9715 3905 50  0000 L CNN
F 2 "" H 9638 3800 50  0001 C CNN
F 3 "~" H 9600 3950 50  0001 C CNN
	1    9600 3950
	1    0    0    -1  
$EndComp
$Comp
L MRDT_Devices:OKI U?
U 1 1 5BCFD699
P 10100 3900
F 0 "U?" H 10150 3850 60  0001 C CNN
F 1 "OKI" H 10300 4181 60  0000 C CNN
F 2 "" H 9900 3800 60  0001 C CNN
F 3 "" H 9900 3800 60  0001 C CNN
	1    10100 3900
	1    0    0    -1  
$EndComp
Text GLabel 10700 3800 2    50   Output ~ 0
5V
Text GLabel 6350 4850 0    50   UnSpc ~ 0
GND
$Comp
L Device:C C?
U 1 1 5BCFDA75
P 5500 4500
F 0 "C?" H 5615 4546 50  0000 L CNN
F 1 "10uF" H 5615 4455 50  0000 L CNN
F 2 "" H 5538 4350 50  0001 C CNN
F 3 "~" H 5500 4500 50  0001 C CNN
	1    5500 4500
	0    -1   -1   0   
$EndComp
Text GLabel 5350 4500 0    50   Input ~ 0
5V
Text GLabel 5650 4950 0    50   Input ~ 0
Dout_NeoPixel1
$Comp
L MRDT_Connectors:AndersonPP Conn1
U 1 1 5BCFE2EB
P 9200 4200
F 0 "Conn1" H 10350 5100 60  0000 C CNN
F 1 "AndersonPP" H 10350 4950 60  0000 C CNN
F 2 "" H 9050 3650 60  0001 C CNN
F 3 "" H 9050 3650 60  0001 C CNN
	1    9200 4200
	1    0    0    -1  
$EndComp
$Comp
L MRDT_Connectors:AndersonPP Conn1
U 2 1 5BCFE2A3
P 9200 3900
F 0 "Conn1" H 9406 4287 60  0000 C CNN
F 1 "AndersonPP" H 9406 4181 60  0000 C CNN
F 2 "" H 9050 3350 60  0001 C CNN
F 3 "" H 9050 3350 60  0001 C CNN
	2    9200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 3800 9900 3800
Connection ~ 9600 3800
Wire Wire Line
	9600 4100 10300 4100
Connection ~ 9600 4100
$Comp
L MRDT_Shields:TM4C129E_Launchpad U?
U 1 1 5BCFEC8C
P 7750 2850
F 0 "U?" H 7780 4127 60  0001 C CNN
F 1 "TM4C129E_Launchpad" H 7800 4000 60  0001 C CNN
F 2 "" H 7750 2850 60  0001 C CNN
F 3 "" H 7750 2850 60  0001 C CNN
	1    7750 2850
	-1   0    0    -1  
$EndComp
$Comp
L MRDT_Connectors:AndersonPP Conn1
U 3 1 5BCFEF35
P 9200 4500
F 0 "Conn1" H 9406 4887 60  0001 C CNN
F 1 "AndersonPP" H 9406 4781 60  0001 C CNN
F 2 "" H 9050 3950 60  0001 C CNN
F 3 "" H 9050 3950 60  0001 C CNN
	3    9200 4500
	1    0    0    -1  
$EndComp
$Comp
L MRDT_Connectors:AndersonPP Conn2
U 4 1 5BCFEFB2
P 9200 5250
F 0 "Conn2" H 9406 5637 60  0001 C CNN
F 1 "AndersonPP" H 9406 5531 60  0001 C CNN
F 2 "" H 9050 4700 60  0001 C CNN
F 3 "" H 9050 4700 60  0001 C CNN
	4    9200 5250
	1    0    0    -1  
$EndComp
$Comp
L MRDT_Devices:LDD-1500L U?
U 1 1 5BCFF8F0
P 1900 4600
F 0 "U?" H 2150 5397 60  0000 C CNN
F 1 "LDD-1500L" H 2150 5291 60  0000 C CNN
F 2 "" H 1900 4600 60  0001 C CNN
F 3 "" H 1900 4600 60  0001 C CNN
	1    1900 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 4450 2600 4500
Wire Wire Line
	2600 4050 2600 4100
$Comp
L Switch:SW_SPDT SW?
U 1 1 5BCFFE8E
P 9700 5750
F 0 "SW?" H 9700 6035 50  0000 C CNN
F 1 "SW_SPDT" H 9700 5944 50  0000 C CNN
F 2 "" H 9700 5750 50  0001 C CNN
F 3 "" H 9700 5750 50  0001 C CNN
	1    9700 5750
	-1   0    0    -1  
$EndComp
Text GLabel 5000 2450 0    50   Output ~ 0
Headlight_OnOff_PWM1
Text Notes 6050 2100 0    50   ~ 0
SPI MOSI(3)
Text Label 2600 4050 0    50   ~ 0
Headlight_V+
Wire Wire Line
	5000 2050 4950 2050
Text Label 9700 3800 0    50   ~ 0
+12V
Wire Wire Line
	1700 4050 1700 4150
$Comp
L MRDT_Connectors:AndersonPP Conn2
U 1 1 5BD01BD2
P 9200 5050
F 0 "Conn2" H 9406 5437 60  0000 C CNN
F 1 "AndersonPP" H 9406 5331 60  0000 C CNN
F 2 "" H 9050 4500 60  0001 C CNN
F 3 "" H 9050 4500 60  0001 C CNN
	1    9200 5050
	1    0    0    -1  
$EndComp
Text GLabel 9600 4400 2    50   Output ~ 0
V+Act
Text GLabel 9600 4950 2    50   Output ~ 0
GND
Text GLabel 9600 5150 2    50   Output ~ 0
PV+
Text GLabel 9500 5650 0    50   Input ~ 0
V+Act
Text GLabel 9500 5850 0    50   Input ~ 0
PV+
Text GLabel 9900 5750 2    50   Output ~ 0
Headlight_Vin
Text GLabel 1700 4100 0    50   Input ~ 0
Headlight_Vin
Text GLabel 1700 4300 0    50   Input ~ 0
Headlight_OnOff_PWM1
Text Label 2700 4450 0    50   ~ 0
Headlight_V-
$Comp
L MRDT_Connectors:Molex_SL_02 Conn1C
U 1 1 5BD0353C
P 3250 4350
F 0 "Conn1C" H 3377 4508 60  0000 L CNN
F 1 "Molex_SL_02" H 3377 4402 60  0000 L CNN
F 2 "" H 3250 4250 60  0001 C CNN
F 3 "" H 3250 4250 60  0001 C CNN
	1    3250 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4300 2700 4300
Wire Wire Line
	2700 4300 2700 4500
Wire Wire Line
	2700 4500 2600 4500
Connection ~ 2600 4500
Wire Wire Line
	2600 4500 2600 4550
Wire Wire Line
	3050 4200 2700 4200
Wire Wire Line
	2700 4200 2700 4100
Wire Wire Line
	2700 4100 2600 4100
Connection ~ 2600 4100
Wire Wire Line
	2600 4100 2600 4150
$Comp
L MRDT_Connectors:Molex_SL_03 Conn2C
U 1 1 5BD03982
P 6550 5000
F 0 "Conn2C" H 6677 5208 60  0000 L CNN
F 1 "Molex_SL_03" H 6677 5102 60  0000 L CNN
F 2 "" H 6550 5000 60  0001 C CNN
F 3 "" H 6550 5000 60  0001 C CNN
	1    6550 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 4750 6350 4500
Wire Wire Line
	5650 4500 6350 4500
Wire Wire Line
	1700 4450 1700 4550
$Comp
L MRDT_Devices:LDD-1500L U?
U 1 1 5BD053EE
P 1900 5550
F 0 "U?" H 2150 6347 60  0000 C CNN
F 1 "LDD-1500L" H 2150 6241 60  0000 C CNN
F 2 "" H 1900 5550 60  0001 C CNN
F 3 "" H 1900 5550 60  0001 C CNN
	1    1900 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5400 2600 5450
Wire Wire Line
	2600 5000 2600 5050
Text Label 2600 5000 0    50   ~ 0
Headlight_V+
Text GLabel 1700 5050 0    50   Input ~ 0
Headlight_Vin
Text GLabel 1700 5250 0    50   Input ~ 0
Headlight_OnOff_PWM2
Text Label 2700 5400 0    50   ~ 0
Headlight_V-
$Comp
L MRDT_Connectors:Molex_SL_02 Conn1D
U 1 1 5BD053FB
P 3250 5300
F 0 "Conn1D" H 3377 5458 60  0000 L CNN
F 1 "Molex_SL_02" H 3377 5352 60  0000 L CNN
F 2 "" H 3250 5200 60  0001 C CNN
F 3 "" H 3250 5200 60  0001 C CNN
	1    3250 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5250 2700 5250
Wire Wire Line
	2700 5250 2700 5450
Wire Wire Line
	2700 5450 2600 5450
Connection ~ 2600 5450
Wire Wire Line
	2600 5450 2600 5500
Wire Wire Line
	3050 5150 2700 5150
Wire Wire Line
	2700 5150 2700 5050
Wire Wire Line
	2700 5050 2600 5050
Connection ~ 2600 5050
Wire Wire Line
	2600 5050 2600 5100
Text GLabel 5000 2550 0    50   Output ~ 0
Headlight_OnOff_PWM2
Wire Wire Line
	1700 5400 1700 5500
Text GLabel 1700 4500 0    50   UnSpc ~ 0
GND
Text GLabel 1700 5450 0    50   UnSpc ~ 0
GND
Text GLabel 7950 2000 2    50   Output ~ 0
Dout_NeoPxiel2
Text Notes 8550 2150 2    50   ~ 0
SPI MOSI(1)
Wire Notes Line
	8850 1650 8850 2950
Wire Notes Line
	8850 2950 4000 2950
Wire Notes Line
	4000 2950 4000 1650
Wire Notes Line
	4000 1650 8850 1650
Wire Notes Line
	700  5600 700  3600
Wire Notes Line
	700  3600 4050 3600
Wire Notes Line
	4050 3600 4050 5600
Wire Notes Line
	4050 5600 700  5600
Wire Notes Line
	8900 6000 8900 3200
Wire Notes Line
	8900 3200 10850 3200
Wire Notes Line
	10850 3200 10850 6000
Wire Notes Line
	10850 6000 8900 6000
$Comp
L Device:R R?
U 1 1 5BD09437
P 5950 4950
F 0 "R?" V 5743 4950 50  0000 C CNN
F 1 "1k" V 5834 4950 50  0000 C CNN
F 2 "" V 5880 4950 50  0001 C CNN
F 3 "~" H 5950 4950 50  0001 C CNN
	1    5950 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 4950 6350 4950
Wire Wire Line
	5800 4950 5650 4950
Text GLabel 6350 5850 0    50   UnSpc ~ 0
GND
$Comp
L Device:C C?
U 1 1 5BD0A00B
P 5500 5500
F 0 "C?" H 5615 5546 50  0000 L CNN
F 1 "10uF" H 5615 5455 50  0000 L CNN
F 2 "" H 5538 5350 50  0001 C CNN
F 3 "~" H 5500 5500 50  0001 C CNN
	1    5500 5500
	0    -1   -1   0   
$EndComp
Text GLabel 5350 5500 0    50   Input ~ 0
5V
Text GLabel 5650 5950 0    50   Input ~ 0
Dout_NeoPixel2
$Comp
L MRDT_Connectors:Molex_SL_03 Conn2C?
U 1 1 5BD0A013
P 6550 6000
F 0 "Conn2C?" H 6677 6208 60  0000 L CNN
F 1 "Molex_SL_03" H 6677 6102 60  0000 L CNN
F 2 "" H 6550 6000 60  0001 C CNN
F 3 "" H 6550 6000 60  0001 C CNN
	1    6550 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 5750 6350 5500
Wire Wire Line
	5650 5500 6350 5500
$Comp
L Device:R R?
U 1 1 5BD0A01B
P 5950 5950
F 0 "R?" V 5743 5950 50  0000 C CNN
F 1 "1k" V 5834 5950 50  0000 C CNN
F 2 "" V 5880 5950 50  0001 C CNN
F 3 "~" H 5950 5950 50  0001 C CNN
	1    5950 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 5950 6350 5950
Wire Wire Line
	5800 5950 5650 5950
Wire Notes Line
	7550 6150 4900 6150
Wire Notes Line
	4900 6150 4900 4150
Wire Notes Line
	4900 4150 7550 4150
Wire Notes Line
	7550 4150 7550 6150
$EndSCHEMATC
