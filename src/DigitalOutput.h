/*
 * DigitalOutput.h
 *
 *  Created on: 08/08/2013
 *      Author: petermilani
 *	Company: Queensland Field Robotics Pty Ltd
 *  website: www.qfr.net.au
 *  Licence: BSD
 *  Gist of Licence:
 * 		- no warranty is express or implied
 * 		- this description is to be kept at head of files using this
 *		 code.
 */

#ifndef DIGITALOUTPUT_H_
#define DIGITALOUTPUT_H_

#include "iopin.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>


#endif /* DIGITALOUTPUT_H_ */

using namespace std;

class DigitalOutput
{
public:

	DigitalOutput();
	~DigitalOutput();

	int openDigitalOutput(int header, int pin);
	int closeDigitalOutput();
	int setNormalPolarity(bool polarity);
	void write(bool val);

private:
	iopin pin;
	char *export_dir;
	FILE *Export_File;
	FILE *Direction_File;



};
