/*
 * DigitalInput.cpp
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
#include "../include/DigitalInput.h"

DigitalInput::DigitalInput()
{
	export_dir = "/sys/class/gpio/";


}

DigitalInput::~DigitalInput()
{

}

/**
 * Opens and sets up the digital input. Exports the pin and sets up the direction of the the pin.
 * header int - the header to use either 8 or 9
 * pin - the pin number on the header
 */
int DigitalInput::openDigitalInput(int header, int pint)
{
	bool direction_error, export_error;

	pin.openPin(header, pint, 7, true, true);



	char exportfilename[40];

	char *filename = "export";

	strcpy(exportfilename, export_dir);
	strcat(exportfilename, filename);


	Export_File = fopen(exportfilename, "w");


	size_t res = fwrite(pin.getGPIONumber(), sizeof(char), 5, Export_File);



	if(res>0)
	{
		export_error = false;

	}
	else
	{
		export_error = true;
	}



	if(fclose(Export_File)!=0)
	{
		export_error = true;
	}


	char classfilename[40];
	strcpy(classfilename, export_dir);
	strcat(classfilename, "gpio");
	strcat(classfilename, pin.getGPIONumber());
	strcat(classfilename, "/direction");
	Direction_File = fopen(classfilename, "r+");



	if(fwrite("in", sizeof(char), 2, Direction_File)>0)
	{
		direction_error = false;
	}
	else
	{
		direction_error = true;
	}



	if(fclose(Direction_File)!=0)
	{
		direction_error = true;
	}

	if((!direction_error)||(!export_error))
	{
		cout << "Pin Opened" << endl;
		return 1;

	}
	else
	{
		cout << "Pin Open Error" << endl;
		return -1;
	}


}

int DigitalInput::setNormalPolarity(bool polarity)
{
	bool write_error=true;
	char classfilename[40];
	strcpy(classfilename, export_dir);
	strcat(classfilename, "gpio");
	strcat(classfilename, pin.getGPIONumber());
	strcat(classfilename, "/active_low");


		char c ='0';

		if (!polarity)
		{
			c = c+1;
		}
		else if (polarity)
		{
			c = '0';
		}


		Direction_File = fopen(classfilename, "r+");


		if(fwrite(&c, sizeof(char), 1, Direction_File)>0)
		{

			write_error = false;

		}
		else
		{

			write_error = true;

		}

		if(fclose(Direction_File)!=0)
		{
			write_error = true;
		}

		if(write_error)
		{
			return -1;

		}
		else
		{
			return 1;
		}



}

/**
 * This function will read a value on a digital pin and return that value as either a 1 "on" or a 0 "off", unless the polarity
 * of the pin is inverted. In that case the return values will be inverted as well. If a value less than 0 is returned then there
 * was an error reading the pin.
 */

bool DigitalInput::read()
{
	bool write_error=true;
		char classfilename[80];
			strcpy(classfilename, export_dir);
			strcat(classfilename, "gpio");
			strcat(classfilename, pin.getGPIONumber());
			strcat(classfilename, "/value");

			char* i;

			size_t result;
			char *buffer;
			buffer = (char*) malloc (sizeof(char)*1);
			Direction_File = fopen(classfilename, "r");

			result = fread(buffer, sizeof(char), 1, Direction_File);

			if(result != 1)
			{

			}
			fclose(Direction_File);



			bool response = false;
			char *p;
			p = "0";
			//cout << p << endl;

			if (strcmp(buffer, p))
			{
				free(buffer);
				response = false;
			}
			else if (strcmp(buffer, p+1))
			{
				free(buffer);
				response = true;
			}

			return response;
}

int DigitalInput::closeDigitalInput()
{

	bool direction_error, export_error;





		char exportfilename[40];

		char *filename = "unexport";

		strcpy(exportfilename, export_dir);
		strcat(exportfilename, filename);


		Export_File = fopen(exportfilename, "w");


		size_t res = fwrite(pin.getGPIONumber(), sizeof(char), 5, Export_File);



		if(res>0)
		{
			export_error = false;

		}
		else
		{
			export_error = true;
		}



		if(fclose(Export_File)!=0)
		{
			export_error = true;
		}


}

