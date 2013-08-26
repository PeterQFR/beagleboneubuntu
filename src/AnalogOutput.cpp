/*
 * AnalogOutput.cpp
 *
 *  Created on: 14/08/2013
 *      Author: petermilani
 *	Company: Queensland Field Robotics Pty Ltd
 *  website: www.qfr.net.au
 *  Licence: GPLv2
 *  Gist of Licence:
 * 		- no warranty is express or implied
 * 		- this description is to be kept at head of files using this
 *		 code.
 */

#include "AnalogOutput.h"

AnalogOutput::AnalogOutput()
{
	export_dir = "/sys/class/pwm/";
}

AnalogOutput::~AnalogOutput()
{

}

/**
 * Checks to ensure that the Pin can be openned as PWM, requests the pin, and starts it with the intended frequency. The start duty cycle is zero.
 * Header - either 8 or 9
 * Pin - Any of the pins on header 8 or 9, only those identified as being PWM capable will be opened.
 * Freq - the Frequency the pwm is set at
 */
int AnalogOutput::openAnalogOutput(int header, int pin, int Freq)
{
	//check the pin is capable of pwm. Pins Capable of PWM are
	//P8, 45, 46, 34, 36, 13, 19,
	//P9, 14,16,28,42,29, 31
	//Collect the directory structure and ensure the modes implemented are correct.

	//Once pin is setup for PWM, then check to see if it is already requested. If requested then Fail, else request, set Freq, and then run the
	// Pin with Duty cycle of 0.5f.




}

int AnalogOutput::openAnalogOutput(int header, int pin, int CyclePeriod)
{

}

int AnalogOutput::setDutyCycle(int DC)
{

}

int AnalogOutput::setPulseWidth(int pulsewidth)
{

}

int AnalogOutput::closeAnalogOutput()
{

}


