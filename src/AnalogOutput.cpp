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
int AnalogOutput::openAnalogOutput(int header, int pint, int Freq)
{
	//check the pin is capable of pwm. Pins Capable of PWM are
	//P8, 45, 46, 34, 36, 13, 19,
	//P9, 14,16,28,42,29, 31
	//Collect the directory structure and ensure the modes implemented are correct.

	//Once pin is setup for PWM, then check to see if it is already requested. If requested then Fail, else request, set Freq, and then run the
	// Pin with Duty cycle of 0.5f.
	if (header==8)
	{
		if(pint==45)
		{

				pwm_dir = "ehrpwm.2:0/";
				pin.openPin(header, pint, 3, true);

		}
		else if (pint== 46)
		{
				pwm_dir = "ehrpwm.2:1/";
				pin.openPin(header, pint, 3, true);
		}
		else if (pint == 34)
		{
			    pwm_dir = "ehrpwm.1:1";
			    pin.openPin(header, pint, 2, true);
		}
		else if(pint == 36)
		{
				pwm_dir = "ehrpwm.1:0/";
				pin.openPin(header, pint, 2, true);
		}
		else if (pint == 13)
		{
				pwm_dir = "ehrpwm.2:1/";
				pin.openPin(header, pint, 4, true);
		}
		else if(pint ==19)
		{
				pwm_dir = "ehrpwm.2:0/";
				pin.openPin(header, pint, 4, true);
		}
		else
		{
				cout <<"Pin is not a PWM pin" << endl;
				return -1;
		}

	}
	else if ( header ==9)
	{
		if (pint == 14)
		{
			pwm_dir =  "ehrpwm.1:0/";
			pin.openPin(header, pint, 6, true);
		}
		else if (pint ==16)
		{
			pwm_dir = "ehrpwm.1:1/";
			pin.openPin(header, pint, 6, true);
		}
		else if (pint == 28)
		{
			pwm_dir = "ecap.2/";
			pin.openPin(header, pint, 4, true);
		}
		else if (pint == 42)
		{
			pwm_dir ="ecap.0/";
			pin.openPin(header, pint, 0, true);
		}
		else if (pint == 29)
		{
			pwm_dir = "ehrpwm.0:0/";
			pin.openPin(header, pint, 1, true);
		}
		else if (pint == 31)
		{
			pwm_dir = "ehrpwm.0:1/";
			pin.openPin(header, pint, 1, true);
		}
		else
		{
			cout <<"Pin is not a PWM pin" << endl;
			return -1;
		}
	}


	char pwmdirfilename [80];


	return 1;

}







int openAnalogOutputPeriod(int header, int pin, int CyclePeriod)
{
		return 1;
}

int AnalogOutput::setDutyCycle(int DC)
{
		return 1;
}

int AnalogOutput::setPulseWidth(int pulsewidth)
{
		return 1;
}

int AnalogOutput::closeAnalogOutput()
{

	return 1;
}


