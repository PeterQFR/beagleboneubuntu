/*
 * AnalogOutput.h
 *
 *  Created on: 14/08/2013
 *      Author: petermilani
 *	Company: Queensland Field Robotics Pty Ltd
 *  website: www.qfr.net.au
 *  Licence: BSD
 *  Gist of Licence:
 * 		- no warranty is express or implied
 * 		- this description is to be kept at head of files using this
 *		 code.
 */

#ifndef ANALOGOUTPUT_H_
#define ANALOGOUTPUT_H_

#include "iopin.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>


#endif /* ANALOGOUTPUT_H_ */

using namespace std;

class AnalogOutput
{
public:
	AnalogOutput();
	~AnalogOutput();

	int openAnalogOutput(int header, int pin, int Freq);
	int openAnalogOutputPeriod(int header, int pin, int CyclePeriod);
	int setDutyCycle(int DC);
	int setPulseWidth(int pulsewidth);
	int closeAnalogOutput();

private:
	char *pwm_dir;
	iopin pin;
	char *export_dir;

	FILE *Export_File;
	FILE *Direction_File;


};
