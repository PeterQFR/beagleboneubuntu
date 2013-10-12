/*
 * DigitalOutput.cpp
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

#include "../include/DigitalOutput.h"

DigitalOutput::DigitalOutput()
{
	export_dir = "/sys/class/gpio/";
}

DigitalOutput::~DigitalOutput()
{

}

int DigitalOutput::openDigitalOutput(int header, int pint)
{

	bool direction_error, export_error;

		pin.openPin(header, pint, 7, true, true);



		char exportfilename[40];

		char *filename = "export";

		strcpy(exportfilename, export_dir);
		strcat(exportfilename, filename);


		Export_File = fopen(exportfilename, "w");


		size_t res = fwrite(pin.getGPIONumber(), sizeof(char), 5, Export_File);

		cout << "pin exported" << endl;

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


		char classfilename[80];
		strcpy(classfilename, export_dir);
		strcat(classfilename, "gpio");
		strcat(classfilename, pin.getGPIONumber());
		strcat(classfilename, "/direction");
		cout << classfilename <<  endl;

		Direction_File = fopen(classfilename, "w");



		cout << "Direction File: " << Direction_File << endl;

		if(fwrite("out", sizeof(char), 3, Direction_File)>0)
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

void DigitalOutput::write(bool val)
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
				Direction_File = fopen(classfilename, "w");

				if(val)
				{
					buffer = "1";
				}
				else if (!val)
				{
					buffer = "0";
				}

				result = fwrite(buffer, sizeof(char), 1, Direction_File);


				fclose(Direction_File);






}
int DigitalOutput::setNormalPolarity(bool polarity)
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
