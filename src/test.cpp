/*
 * test.cpp
 *
 *  Created on: 05/08/2013
 *      Author: petermilani
 */


#include "DigitalInput.h"
#include "DigitalOutput.h"
#include "AnalogOutput.h"
#include "unistd.h"
#include "SPI.h"

using namespace std;

int main() {


	SPI jointencoder;


	jointencoder.open(2,0);

	printf("Encoder open \n");
	jointencoder.setSpeed(1000000);
	printf("speed set \n");
	uint8_t readbuf[2];

	while(1)
	{
		jointencoder.read(readbuf, 2);
		int read = 0;
		read = readbuf[1]+readbuf[0]*255 + 2*(readbuf[1]&128);
		read =(read & 65472);
		read = read >> 5;
		//printf("joint encoder %d \n", read);

	}


//	cout << "writing mux settings " << endl; // prints !!!Hello World!!!
//
//
//	AnalogOutput pin;
//
//	int suc = pin.openAnalogOutput(9, 42, 1000);
//
//	int foo = pin.setDutyCycle(0);
//
//	cout << "Analog Pin Opened" << endl;
//
//	int Dpc =0;
//	while(1)
//	{
//		Dpc++;
//        sleep(1);
//		pin.setDutyCycle(Dpc);
//
//		if (Dpc >100)
//		{
//			Dpc =0;
//		}
//
//	}

	}


