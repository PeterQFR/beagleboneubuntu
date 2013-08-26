/*
 * DigitalInput.h
 *
 *  Created on: 05/08/2013
 *      Author: petermilani
 *	Company: Queensland Field Robotics Pty Ltd
 *  website: www.qfr.net.au
 *  Licence: BSD
 *  Gist of Licence:
 * 		- no warranty is express or implied
 * 		- this description is to be kept at head of files using this
 *		 code.
 */

#ifndef DIGITALINPUT_H_
#define DIGITALINPUT_H_


#include "iopin.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

#endif /* DIGITALINPUT_H_ */

class DigitalInput
{
public:

	DigitalInput();
	~DigitalInput();

	int openDigitalInput(int header, int pin);
	int closeDigitalInput();
	int setNormalPolarity(bool polarity);
	bool read();

private:
	iopin pin;
	char *export_dir;
	FILE *Export_File;
	FILE *Direction_File;



};
