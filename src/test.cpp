/*
 * test.cpp
 *
 *  Created on: 05/08/2013
 *      Author: petermilani
 */


#include "DigitalInput.h"
#include "DigitalOutput.h"

using namespace std;

int main() {
	cout << "writing mux settings " << endl; // prints !!!Hello World!!!

	DigitalInput pin;
	DigitalOutput pin2;

	int suc = pin.openDigitalInput(9, 11);

	int suc2 = pin2.openDigitalOutput(9, 13);

	cout << "Digital Pin Opened" << endl;


	while(1)
	{
		bool res = false;
		res =pin.read();

		if(res)
		{
			pin2.write(true);
		}
		else if (!res)
		{
			pin2.write(false);
		}

	}

	}


