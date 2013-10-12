/*
 * message.h
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

#ifndef HMMv4_CONFIGMSG_H_
#define HMMv4_CONFIGMSG_H_

#include <stdint.h>


#endif /* MESSAGE_H_ */
using namespace std;

class hmmv4_configmsg{


public:
	union myint16_t{
		uint16_t ui16;
		int16_t i16;
		uint8_t data[2];
	};

	union config_t{
		struct {
			uint16_t commandtype;
			myint16_t UpperLimits[4];
			myint16_t LowerLimits[4];
			myint16_t JointZeros[4];
			int8_t JointPolarity[4];
			myint16_t P[4];
			myint16_t I[4];
			myint16_t D[4];

		} ;


		uint8_t data[54];
	} ;

	union run_t{
		struct{
			uint16_t commandtype;
			int16_t command[4];
		} master;

		struct{
			uint16_t commandtype;
			uint16_t jointpos[4];
			int16_t jointvel[4];
			uint8_t jointvalid[4];
		}slave;

		uint8_t data[21];


	} ;

	config_t config;
	run_t run;

	void change_endian();

	hmmv4_configmsg();
	~hmmv4_configmsg();


};
