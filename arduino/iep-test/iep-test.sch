EESchema Schematic File Version 4
EELAYER 30 0
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
L Connector:Conn_01x10_Male J1
U 1 1 619BE887
P 2050 1250
F 0 "J1" H 2158 1831 50  0000 C CNN
F 1 "Inputs" H 2158 1740 50  0000 C CNN
F 2 "" H 2050 1250 50  0001 C CNN
F 3 "~" H 2050 1250 50  0001 C CNN
	1    2050 1250
	1    0    0    -1  
$EndComp
$Comp
L Oscillator:MIC1557YM5 U?
U 1 1 619BDCE5
P 3500 1500
F 0 "U?" H 3600 985 50  0000 C CNN
F 1 "MIC1557YM5" H 3600 1076 50  0000 C CNN
F 2 "" H 3250 1450 50  0001 C CNN
F 3 "" H 3250 1450 50  0001 C CNN
	1    3500 1500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 619BE405
P 4200 1100
F 0 "R1" H 4130 1054 50  0000 R CNN
F 1 "100" H 4130 1145 50  0000 R CNN
F 2 "" V 4130 1100 50  0001 C CNN
F 3 "~" H 4200 1100 50  0001 C CNN
	1    4200 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 1750 2350 1750
Text Label 2550 1750 2    50   ~ 0
V+
$Comp
L power:GND #PWR?
U 1 1 619C0804
P 2400 1600
F 0 "#PWR?" H 2400 1350 50  0001 C CNN
F 1 "GND" V 2405 1472 50  0000 R CNN
F 2 "" H 2400 1600 50  0001 C CNN
F 3 "" H 2400 1600 50  0001 C CNN
	1    2400 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2250 1550 2300 1550
Wire Wire Line
	2300 1550 2300 1600
Wire Wire Line
	2300 1650 2250 1650
Wire Wire Line
	2400 1600 2300 1600
Connection ~ 2300 1600
Wire Wire Line
	2300 1600 2300 1650
Wire Wire Line
	2950 1250 3050 1250
Text Label 2950 1250 0    50   ~ 0
V+
Wire Wire Line
	2250 850  2450 850 
Text Label 2450 850  2    50   ~ 0
SQ
Wire Wire Line
	2250 950  2450 950 
Wire Wire Line
	2250 1050 2450 1050
Wire Wire Line
	2250 1150 2450 1150
Wire Wire Line
	2250 1250 2450 1250
Wire Wire Line
	2250 1350 2450 1350
Wire Wire Line
	2250 1450 2450 1450
Text Label 2450 950  2    50   ~ 0
P1
Text Label 2450 1050 2    50   ~ 0
P2
Text Label 2450 1150 2    50   ~ 0
L1
Text Label 2450 1250 2    50   ~ 0
L2
Text Label 2450 1350 2    50   ~ 0
L3
Text Label 2450 1450 2    50   ~ 0
L4
Wire Wire Line
	3100 1400 2950 1400
Text Label 2950 1400 0    50   ~ 0
SQ
Wire Wire Line
	3700 1250 3700 900 
Wire Wire Line
	3700 900  3050 900 
Wire Wire Line
	3050 900  3050 1250
Connection ~ 3050 1250
Wire Wire Line
	3050 1250 3100 1250
$Comp
L power:GND #PWR?
U 1 1 619C6254
P 3800 1350
F 0 "#PWR?" H 3800 1100 50  0001 C CNN
F 1 "GND" V 3805 1222 50  0000 R CNN
F 2 "" H 3800 1350 50  0001 C CNN
F 3 "" H 3800 1350 50  0001 C CNN
	1    3800 1350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3700 1350 3800 1350
$Comp
L Device:R_POT RV1
U 1 1 619C79FA
P 4200 1450
F 0 "RV1" V 4085 1450 50  0000 C CNN
F 1 "R_POT" V 4000 1400 50  0000 C CNN
F 2 "" H 4200 1450 50  0001 C CNN
F 3 "~" H 4200 1450 50  0001 C CNN
	1    4200 1450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3700 1450 3850 1450
Wire Wire Line
	4200 1300 4200 1250
Wire Wire Line
	4200 950  4200 900 
Wire Wire Line
	4200 900  4450 900 
Text Label 4450 900  2    50   ~ 0
SQ
NoConn ~ 4450 1450
Wire Wire Line
	4350 1450 4450 1450
$Comp
L Device:C C1
U 1 1 619CACE1
P 3850 1700
F 0 "C1" H 3750 1800 50  0000 L CNN
F 1 "0.1uF" H 3650 1600 50  0000 L CNN
F 2 "" H 3888 1550 50  0001 C CNN
F 3 "~" H 3850 1700 50  0001 C CNN
	1    3850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1450 3850 1550
Connection ~ 3850 1450
Wire Wire Line
	3850 1450 4050 1450
$Comp
L power:GND #PWR?
U 1 1 619CD596
P 3850 1900
F 0 "#PWR?" H 3850 1650 50  0001 C CNN
F 1 "GND" H 3855 1727 50  0000 C CNN
F 2 "" H 3850 1900 50  0001 C CNN
F 3 "" H 3850 1900 50  0001 C CNN
	1    3850 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1850 3850 1900
$Comp
L Device:R_POT RV2
U 1 1 619D4E16
P 3650 2700
F 0 "RV2" V 3535 2700 50  0000 C CNN
F 1 "R_POT" V 3450 2650 50  0000 C CNN
F 2 "" H 3650 2700 50  0001 C CNN
F 3 "~" H 3650 2700 50  0001 C CNN
	1    3650 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 2700 3350 2700
Wire Wire Line
	3800 2700 3950 2700
$Comp
L Device:R R2
U 1 1 619D6AC6
P 4100 2700
F 0 "R2" V 3893 2700 50  0000 C CNN
F 1 "R" V 3984 2700 50  0000 C CNN
F 2 "" V 4030 2700 50  0001 C CNN
F 3 "~" H 4100 2700 50  0001 C CNN
	1    4100 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 2700 4450 2700
Text Label 3350 2700 0    50   ~ 0
P1
Text Label 4450 2700 2    50   ~ 0
V+
$Comp
L Device:R_POT RV3
U 1 1 619D8D24
P 3650 3150
F 0 "RV3" V 3535 3150 50  0000 C CNN
F 1 "R_POT" V 3450 3100 50  0000 C CNN
F 2 "" H 3650 3150 50  0001 C CNN
F 3 "~" H 3650 3150 50  0001 C CNN
	1    3650 3150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 3150 3350 3150
Wire Wire Line
	3800 3150 3950 3150
$Comp
L Device:R R3
U 1 1 619D8D2C
P 4100 3150
F 0 "R3" V 3893 3150 50  0000 C CNN
F 1 "R" V 3984 3150 50  0000 C CNN
F 2 "" V 4030 3150 50  0001 C CNN
F 3 "~" H 4100 3150 50  0001 C CNN
	1    4100 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 3150 4450 3150
Text Label 3350 3150 0    50   ~ 0
P2
Text Label 4450 3150 2    50   ~ 0
V+
$Comp
L Device:R R4
U 1 1 619D995E
P 5450 2000
F 0 "R4" V 5657 2000 50  0000 C CNN
F 1 "100" V 5566 2000 50  0000 C CNN
F 2 "" V 5380 2000 50  0001 C CNN
F 3 "~" H 5450 2000 50  0001 C CNN
	1    5450 2000
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q1
U 1 1 619DA7F9
P 5900 2000
F 0 "Q1" H 6091 2046 50  0000 L CNN
F 1 "BC817" H 6091 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6100 1925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 5900 2000 50  0001 L CNN
	1    5900 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2000 5700 2000
Wire Wire Line
	6000 1650 6000 1800
$Comp
L Device:R R5
U 1 1 619DCE08
P 6000 1500
F 0 "R5" H 6070 1546 50  0000 L CNN
F 1 "100" H 6070 1455 50  0000 L CNN
F 2 "" V 5930 1500 50  0001 C CNN
F 3 "~" H 6000 1500 50  0001 C CNN
	1    6000 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 619DDAD2
P 6000 1200
F 0 "D1" V 6039 1082 50  0000 R CNN
F 1 "LED" V 5948 1082 50  0000 R CNN
F 2 "" H 6000 1200 50  0001 C CNN
F 3 "~" H 6000 1200 50  0001 C CNN
	1    6000 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 1050 6000 900 
Text Label 6000 900  3    50   ~ 0
V+
$Comp
L power:GND #PWR?
U 1 1 619DF6C8
P 6000 2300
F 0 "#PWR?" H 6000 2050 50  0001 C CNN
F 1 "GND" H 6005 2127 50  0000 C CNN
F 2 "" H 6000 2300 50  0001 C CNN
F 3 "" H 6000 2300 50  0001 C CNN
	1    6000 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2200 6000 2300
$Comp
L Device:R R6
U 1 1 619ED208
P 6700 2000
F 0 "R6" V 6907 2000 50  0000 C CNN
F 1 "100" V 6816 2000 50  0000 C CNN
F 2 "" V 6630 2000 50  0001 C CNN
F 3 "~" H 6700 2000 50  0001 C CNN
	1    6700 2000
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q2
U 1 1 619ED20E
P 7150 2000
F 0 "Q2" H 7341 2046 50  0000 L CNN
F 1 "BC817" H 7341 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7350 1925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 7150 2000 50  0001 L CNN
	1    7150 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 2000 6950 2000
Wire Wire Line
	7250 1650 7250 1800
$Comp
L Device:R R7
U 1 1 619ED216
P 7250 1500
F 0 "R7" H 7320 1546 50  0000 L CNN
F 1 "100" H 7320 1455 50  0000 L CNN
F 2 "" V 7180 1500 50  0001 C CNN
F 3 "~" H 7250 1500 50  0001 C CNN
	1    7250 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 619ED21C
P 7250 1200
F 0 "D2" V 7289 1082 50  0000 R CNN
F 1 "LED" V 7198 1082 50  0000 R CNN
F 2 "" H 7250 1200 50  0001 C CNN
F 3 "~" H 7250 1200 50  0001 C CNN
	1    7250 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7250 1050 7250 900 
Text Label 7250 900  3    50   ~ 0
V+
$Comp
L power:GND #PWR?
U 1 1 619ED224
P 7250 2300
F 0 "#PWR?" H 7250 2050 50  0001 C CNN
F 1 "GND" H 7255 2127 50  0000 C CNN
F 2 "" H 7250 2300 50  0001 C CNN
F 3 "" H 7250 2300 50  0001 C CNN
	1    7250 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2200 7250 2300
$Comp
L Device:R R8
U 1 1 619F3B8A
P 8000 2000
F 0 "R8" V 8207 2000 50  0000 C CNN
F 1 "100" V 8116 2000 50  0000 C CNN
F 2 "" V 7930 2000 50  0001 C CNN
F 3 "~" H 8000 2000 50  0001 C CNN
	1    8000 2000
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q3
U 1 1 619F3B90
P 8450 2000
F 0 "Q3" H 8641 2046 50  0000 L CNN
F 1 "BC817" H 8641 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8650 1925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 8450 2000 50  0001 L CNN
	1    8450 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2000 8250 2000
Wire Wire Line
	8550 1650 8550 1800
$Comp
L Device:R R9
U 1 1 619F3B98
P 8550 1500
F 0 "R9" H 8620 1546 50  0000 L CNN
F 1 "100" H 8620 1455 50  0000 L CNN
F 2 "" V 8480 1500 50  0001 C CNN
F 3 "~" H 8550 1500 50  0001 C CNN
	1    8550 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 619F3B9E
P 8550 1200
F 0 "D3" V 8589 1082 50  0000 R CNN
F 1 "LED" V 8498 1082 50  0000 R CNN
F 2 "" H 8550 1200 50  0001 C CNN
F 3 "~" H 8550 1200 50  0001 C CNN
	1    8550 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8550 1050 8550 900 
Text Label 8550 900  3    50   ~ 0
V+
$Comp
L power:GND #PWR?
U 1 1 619F3BA6
P 8550 2300
F 0 "#PWR?" H 8550 2050 50  0001 C CNN
F 1 "GND" H 8555 2127 50  0000 C CNN
F 2 "" H 8550 2300 50  0001 C CNN
F 3 "" H 8550 2300 50  0001 C CNN
	1    8550 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 2200 8550 2300
$Comp
L Device:R R10
U 1 1 619F3BAD
P 9250 2000
F 0 "R10" V 9457 2000 50  0000 C CNN
F 1 "100" V 9366 2000 50  0000 C CNN
F 2 "" V 9180 2000 50  0001 C CNN
F 3 "~" H 9250 2000 50  0001 C CNN
	1    9250 2000
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q4
U 1 1 619F3BB3
P 9700 2000
F 0 "Q4" H 9891 2046 50  0000 L CNN
F 1 "BC817" H 9891 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 9900 1925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BC818-D.pdf" H 9700 2000 50  0001 L CNN
	1    9700 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 2000 9500 2000
Wire Wire Line
	9800 1650 9800 1800
$Comp
L Device:R R11
U 1 1 619F3BBB
P 9800 1500
F 0 "R11" H 9870 1546 50  0000 L CNN
F 1 "100" H 9870 1455 50  0000 L CNN
F 2 "" V 9730 1500 50  0001 C CNN
F 3 "~" H 9800 1500 50  0001 C CNN
	1    9800 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 619F3BC1
P 9800 1200
F 0 "D4" V 9839 1082 50  0000 R CNN
F 1 "LED" V 9748 1082 50  0000 R CNN
F 2 "" H 9800 1200 50  0001 C CNN
F 3 "~" H 9800 1200 50  0001 C CNN
	1    9800 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9800 1050 9800 900 
Text Label 9800 900  3    50   ~ 0
V+
$Comp
L power:GND #PWR?
U 1 1 619F3BC9
P 9800 2300
F 0 "#PWR?" H 9800 2050 50  0001 C CNN
F 1 "GND" H 9805 2127 50  0000 C CNN
F 2 "" H 9800 2300 50  0001 C CNN
F 3 "" H 9800 2300 50  0001 C CNN
	1    9800 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 2200 9800 2300
Wire Wire Line
	5300 2000 5300 2750
Wire Wire Line
	5300 2750 5100 2750
Wire Wire Line
	6550 2000 6550 2900
Wire Wire Line
	6550 2900 5100 2900
Wire Wire Line
	7850 2000 7850 3050
Wire Wire Line
	7850 3050 5100 3050
Wire Wire Line
	9100 2000 9100 3200
Wire Wire Line
	9100 3200 5100 3200
Text Label 5100 2750 0    50   ~ 0
L1
Text Label 5100 2900 0    50   ~ 0
L2
Text Label 5100 3050 0    50   ~ 0
L3
Text Label 5100 3200 0    50   ~ 0
L4
Wire Notes Line
	4800 750  10300 750 
Wire Notes Line
	10300 750  10300 3550
Wire Notes Line
	10300 3550 4800 3550
Wire Notes Line
	4800 3550 4800 750 
Text Notes 9700 3500 0    50   ~ 0
LED CONTROL
$Comp
L Device:C C2
U 1 1 61A0D66E
P 2350 1950
F 0 "C2" H 2465 1996 50  0000 L CNN
F 1 "C" H 2465 1905 50  0000 L CNN
F 2 "" H 2388 1800 50  0001 C CNN
F 3 "~" H 2350 1950 50  0001 C CNN
	1    2350 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 1800 2350 1750
Connection ~ 2350 1750
Wire Wire Line
	2350 1750 2550 1750
$Comp
L power:GND #PWR?
U 1 1 61A109C8
P 2350 2100
F 0 "#PWR?" H 2350 1850 50  0001 C CNN
F 1 "GND" H 2355 1927 50  0000 C CNN
F 2 "" H 2350 2100 50  0001 C CNN
F 3 "" H 2350 2100 50  0001 C CNN
	1    2350 2100
	1    0    0    -1  
$EndComp
Text Notes 4200 3500 0    50   ~ 0
POT OUTPUT
Wire Notes Line
	2850 750  2850 2200
Wire Notes Line
	2850 2200 4700 2200
Wire Notes Line
	4700 2200 4700 750 
Wire Notes Line
	4700 750  2850 750 
Text Notes 3950 2150 0    50   ~ 0
SQUARE WAVE GEN
Wire Notes Line
	3200 2450 3200 3550
Wire Notes Line
	3200 3550 4700 3550
Wire Notes Line
	4700 3550 4700 2450
Wire Notes Line
	4700 2450 3200 2450
$EndSCHEMATC
