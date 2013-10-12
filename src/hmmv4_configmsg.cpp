/*
 * message.cpp
 *
 *  Created on: 06/10/2013
 *      Author: petermilani
 *	Company: Queensland Field Robotics Pty Ltd
 *  website: www.qfr.net.au
 *  Licence: BSD
 *  Gist of Licence:
 * 		- no warranty is express or implied
 * 		- this description is to be kept at head of files using this
 *		 code.
 */
#include "hmmv4_configmsg.h"

hmmv4_configmsg::~hmmv4_configmsg()
{
	config.commandtype = (uint16_t) 'c';
	run.master.commandtype = (uint16_t) 'r';
	run.slave.commandtype= (uint16_t) 'r';
}

hmmv4_configmsg::hmmv4_configmsg()
{

}

void hmmv4_configmsg::change_endian(void)
{
	uint8_t tmp;
	//tmp.ui16=0;

	for (int i =0; i<4; i++)
	{
		//P long integers
		uint8_t tmp1;
		uint8_t tmp2;
		uint8_t tmp3;
		uint8_t tmp4;
		uint8_t tmp5;
		uint8_t tmp6;







	}
}



