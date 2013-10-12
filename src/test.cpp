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
#include "time.h"
#include "hmmv4_configmsg.h"

using namespace std;





int main() {


	SPI jointencoder;


	jointencoder.open(2,0);
	jointencoder.setMode(1);
	printf("Encoder open \n");
	jointencoder.setSpeed(2000000);
	printf("speed set \n");
	uint8_t writebuf[54];
	uint8_t readbuf[54];
	char q = 'c';



	hmmv4_configmsg msg;




	msg.config.commandtype =(uint8_t) q;
	msg.config.UpperLimits[0].ui16 = 784;
	msg.config.UpperLimits[1].ui16  = 784;
	msg.config.UpperLimits[2].ui16  = 784;
	msg.config.UpperLimits[3].ui16  = 784;
	msg.config.LowerLimits[0].ui16  = 223;
	msg.config.LowerLimits[1].ui16  = 223;
	msg.config.LowerLimits[2].ui16  = 223;
	msg.config.LowerLimits[3].ui16  = 223;
	msg.config.JointZeros[0].ui16  = 512;
	msg.config.JointZeros[1].ui16  = 512;
	msg.config.JointZeros[2].ui16  = 512;
	msg.config.JointZeros[3].ui16  = 512;
	msg.config.JointPolarity[0] = -1;
	msg.config.JointPolarity[1] =-1;
	msg.config.JointPolarity[2] =-1;
	msg.config.JointPolarity[3] =-1;
	msg.config.P[0].i16=4000;
	msg.config.P[1].i16=4000;
	msg.config.P[2].i16=4000;
	msg.config.P[3].i16=4000;
	msg.config.I[0].i16=1;
	msg.config.I[1].i16=1;
	msg.config.I[2].i16=1;
	msg.config.I[3].i16=1;
	msg.config.D[0].i16=24;
	msg.config.D[1].i16=24;
	msg.config.D[2].i16=24;
	msg.config.D[3].i16=24;

	msg.run.master.commandtype = (uint16_t) 'r';
	msg.run.master.command[0] = 124;
	msg.run.master.command[1] = 123;
	msg.run.master.command[2] = -12;
	msg.run.master.command[3] = -22;
	//msg.change_endian();

	while(1)
	{




			for(int i =0; i< sizeof(msg.run.data); i++)
			{
				writebuf[i]=msg.run.data[i];

				//printf("D: %d,  %d \n", i, msg.run.data[i]);
			}

			//printf("L0: %d, %d, %d", msg.config.P[0].i16, msg.config.P[0].data[0], msg.config.P[0].data[1]);

		int r =jointencoder.xfer1(writebuf, readbuf, sizeof(msg.run.data));


		for(int i = 0; i< sizeof(msg.run.data); i++)
		{
			msg.run.data[i] = readbuf[i];

		}

		printf("Joint pos: %d, %d, %d, %d", msg.run.slave.jointpos[0], msg.run.slave.jointpos[1], msg.run.slave.jointpos[2],msg.run.slave.jointpos[3]);


		if (r<0)
			printf("joint encoder fuckup %d \n", r);
		time_t timer;
		time(&timer);
		/*int read = 0;
		read = readbuf[1]+readbuf[0]*255 + 2*(readbuf[1]&128);
		read =(read & 65472);
		read = read >> 5;*/
		printf("joint encoder transferred \n" );



		time_t currenttime;

		time(&currenttime);

		while(difftime(currenttime, timer)<3)
		{

			time(&currenttime);
		}


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


