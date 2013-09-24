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
 * Opens a PWM output with control over the cycle period instead of the Frequency.
 * Header: - the header 8 or 9
 * pint: - the pin number in that header
 * CyclePeriod:  the period for a full PWM cycle, there is no validity checking so keep it realistic.
 */
int AnalogOutput::openAnalogOutputPeriod(int header, int pint, int CyclePeriod)
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
					pin.openPin(header, pint, 3, true, true);

			}
			else if (pint== 46)
			{
					pwm_dir = "ehrpwm.2:1/";
					pin.openPin(header, pint, 3, true, true);
			}
			else if (pint == 34)
			{
				    pwm_dir = "ehrpwm.1:1";
				    pin.openPin(header, pint, 2, true, true);
			}
			else if(pint == 36)
			{
					pwm_dir = "ehrpwm.1:0/";
					pin.openPin(header, pint, 2, true, true);
			}
			else if (pint == 13)
			{
					pwm_dir = "ehrpwm.2:1/";
					pin.openPin(header, pint, 4, true, true);
			}
			else if(pint ==19)
			{
					pwm_dir = "ehrpwm.2:0/";
					pin.openPin(header, pint, 4, true, true);
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
				pin.openPin(header, pint, 6, true, true);
			}
			else if (pint ==16)
			{
				pwm_dir = "ehrpwm.1:1/";
				pin.openPin(header, pint, 6, true, true);
			}
			else if (pint == 28)
			{
				pwm_dir = "ecap.2/";
				pin.openPin(header, pint, 4, true, true);
			}
			else if (pint == 42)
			{
				pwm_dir ="ecap.0/";
				pin.openPin(header, pint, 0, true, true);
			}
			else if (pint == 29)
			{
				pwm_dir = "ehrpwm.0:0/";
				pin.openPin(header, pint, 1, true, true);
			}
			else if (pint == 31)
			{
				pwm_dir = "ehrpwm.0:1/";
				pin.openPin(header, pint, 1, true, true);
			}
			else
			{
				cout <<"Pin is not a PWM pin" << endl;
				return -1;
			}
		}


		//Request the PWM module
		char requestfilename [80];

		strcpy(requestfilename, export_dir);
		strcat(requestfilename, pwm_dir);
		strcat(requestfilename, "request");

		Request_File = fopen(requestfilename, "w");
		char *buffer;
		buffer = (char*) malloc (sizeof(char)*1);
		buffer = "1";

		size_t res = fwrite(buffer, sizeof(char), 1, Request_File);

		if (res!=1)
		{
			printf("PWM Request Failed, PWM module %s probably in use /n", pwm_dir);
			return -1;
		}

		fclose(Request_File);

		//set the Period Frequency
		char perfreqfilename [80];
		strcpy(perfreqfilename, export_dir);
		strcat(perfreqfilename, pwm_dir);
		strcat(perfreqfilename, "period_freq");

		char period[10];

		  sprintf(period, "%d", CyclePeriod);

		  cout << period << endl;

		  Period_freq_File = fopen(perfreqfilename, "w");
		  res = fwrite(period, sizeof(char), 10, Period_freq_File);

		  fclose(Period_freq_File);

		  //Set the module to run
		  char runfilename [80];
		  strcpy(runfilename, export_dir);
		  strcat(runfilename, pwm_dir);
		  strcat(runfilename, "run");

		  Run_File = fopen(runfilename, "w");

		  res = fwrite(buffer, sizeof(char), 1, Run_File);

		  fclose(Run_File);



		return 1;



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
				pin.openPin(header, pint, 3, true, true);

		}
		else if (pint== 46)
		{
				pwm_dir = "ehrpwm.2:1/";
				pin.openPin(header, pint, 3, true, true);
		}
		else if (pint == 34)
		{
			    pwm_dir = "ehrpwm.1:1";
			    pin.openPin(header, pint, 2, true, true);
		}
		else if(pint == 36)
		{
				pwm_dir = "ehrpwm.1:0/";
				pin.openPin(header, pint, 2, true, true);
		}
		else if (pint == 13)
		{
				pwm_dir = "ehrpwm.2:1/";
				pin.openPin(header, pint, 4, true, true);
		}
		else if(pint ==19)
		{
				pwm_dir = "ehrpwm.2:0/";
				pin.openPin(header, pint, 4, true, true);
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
			pin.openPin(header, pint, 6, true, true);
		}
		else if (pint ==16)
		{
			pwm_dir = "ehrpwm.1:1/";
			pin.openPin(header, pint, 6, true, true);
		}
		else if (pint == 28)
		{
			pwm_dir = "ecap.2/";
			pin.openPin(header, pint, 4, true, true);
		}
		else if (pint == 42)
		{
			pwm_dir ="ecap.0/";
			pin.openPin(header, pint, 0, true, true);
		}
		else if (pint == 29)
		{
			pwm_dir = "ehrpwm.0:0/";
			pin.openPin(header, pint, 1, true, true);
		}
		else if (pint == 31)
		{
			pwm_dir = "ehrpwm.0:1/";
			pin.openPin(header, pint, 1, true, true);
		}
		else
		{
			cout <<"Pin is not a PWM pin" << endl;
			return -1;
		}
	}


	//Request the PWM module
	char requestfilename [80];

	strcpy(requestfilename, export_dir);
	strcat(requestfilename, pwm_dir);
	strcat(requestfilename, "request");

	Request_File = fopen(requestfilename, "w");
	char *buffer;
	buffer = (char*) malloc (sizeof(char)*1);
	buffer = "1";

	size_t res = fwrite(buffer, sizeof(char), 1, Request_File);

	if (res!=1)
	{
		printf("PWM Request Failed, PWM module %s probably in use /n", pwm_dir);
		return -1;
	}

	fclose(Request_File);

	//set the Period Frequency
	char perfreqfilename [80];
	strcpy(perfreqfilename, export_dir);
	strcat(perfreqfilename, pwm_dir);
	strcat(perfreqfilename, "period_freq");

	char period[10];

	  sprintf(period, "%d", Freq);

	  cout << period << endl;

	  Period_freq_File = fopen(perfreqfilename, "w");
	  res = fwrite(period, sizeof(char), 10, Period_freq_File);

	  fclose(Period_freq_File);

	  //Set the module to run
	  char runfilename [80];
	  strcpy(runfilename, export_dir);
	  strcat(runfilename, pwm_dir);
	  strcat(runfilename, "run");

	  Run_File = fopen(runfilename, "w");

	  res = fwrite(buffer, sizeof(char), 1, Run_File);

	  fclose(Run_File);



	return 1;

}

/**
 * Sets the duty cycle as an expression of percentage 0 - 100
 * DC - int 0- 100
 */

int AnalogOutput::setDutyCycle(int DC)
{
	char requestfilename [80];

	strcpy(requestfilename, export_dir);
	strcat(requestfilename, pwm_dir);
	strcat(requestfilename, "duty_percent");

	char duty[4];

		  sprintf(duty, "%d", DC);

		  DutyPC_File = fopen(requestfilename, "w");

		  size_t res = fwrite(duty, sizeof(char), 4, DutyPC_File);
		  fclose(DutyPC_File);
		  cout << DC << endl;

	return 1;
}

/**
 * Sets the Pulsewidth in Nanoseconds, operator is to ensure that the pulsewidth can be executed in the required
 * timeframe and is not greater than the overall PWM period.
 * pulsewidth
 */
int AnalogOutput::setPulseWidth(int pulsewidth)
{
	char requestfilename [80];

		strcpy(requestfilename, export_dir);
		strcat(requestfilename, pwm_dir);
		strcat(requestfilename, "duty_ns");

		char duty[4];

			  sprintf(duty, "%d", pulsewidth);

			  DutyPC_File = fopen(requestfilename, "w");

			  size_t res = fwrite(duty, sizeof(char), 4, DutyPC_File);
			  fclose(DutyPC_File);


		return 1;

}

int AnalogOutput::closeAnalogOutput()
{
	     char *buffer;
	     buffer = (char*) malloc (sizeof(char)*1);
		 buffer = "0";

		 //Stop the module running.
		  char runfilename [80];
		  strcpy(runfilename, export_dir);
		  strcat(runfilename, pwm_dir);
		  strcat(runfilename, "run");

		  Run_File = fopen(runfilename, "w");

		  size_t res = fwrite(buffer, sizeof(char), 1, Run_File);

		  fclose(Run_File);

		  //Release the module for other uses.
		  char requestfilename [80];

		  	strcpy(requestfilename, export_dir);
		  	strcat(requestfilename, pwm_dir);
		  	strcat(requestfilename, "request");

		  	Request_File = fopen(requestfilename, "w");


		  	res = fwrite(buffer, sizeof(char), 1, Request_File);

		  	if (res!=1)
		  	{
		  		printf("PWM Request Failed, PWM module %s probably in use /n", pwm_dir);
		  		return -1;
		  	}

		  	fclose(Request_File);

	return 1;
}


