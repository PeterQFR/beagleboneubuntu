/*
 * iopin.h
 *
 *  Created on: 05/08/2013
 *      Author: petermilani
 *      Licence: BSD
 *
 *      This header file will detail the basic pin setup, particularly the setting of the appropriate pin mux
 *      settings.
 */
#pragma once
#ifndef IOPIN_H_
#define IOPIN_H_
#include <stdio.h>
#include <iostream>
#include <cstring>
#endif

using namespace std;

class iopin
{
private:
	char *Mux_dir;
	char *Name;
	FILE *MuxFile;
	bool validpin;
	char *gpiono;


public:

	iopin();
	void openPin(int bank, int pin, int mode, bool pullup);

	~iopin();
	char* getGPIONumber();




};
/* IOPIN_H_ */
