beagleboneubuntu
================

Beaglebone libraries created for use with ubuntu

What this is?

This library is a library written in C++ for use with the beaglebone A6 variant. Its been tested on this device an allows access to DigitalIO, AnalogIO, SPI and soon I2C. It can be freely downloaded and used without any warranty expressed or implied. 

<b>DigitalIO.<b>

The DigitalIO allows digital input and digital output for any pin on the P8 or P9 header. It uses the filesystem to access the pins. The pin first must be declared and initialised but prior to use must call openDigitalInput() or openDigitalOutput() and specify the pin that digitalIO function applies to. The pin is identified by the header number and pin number in the header e.g.

DigitalInput pin = new DigitalInput();
pin.openDigitalInput(8, 43);

will initialise and open pin 43 on header 8 as a digital input. 

The pin is polled by calling pin.read() and returns an integer equivalent to the voltage on the pin.

Other methods for DigitalInput and DigitalOutput allow the changing of polarity for the pin.

<b>AnalogIO<b>

The AnalogIO uses the file system to achieve analogOutput (or PWM) on one of the beaglebone's 8 PWM modules. Or to read one of the 6 ADCs.



<b>SPI<b> 

The SPI source was taken from from prianna32's library on github https://github.com/piranha32/IOoo.git

To use is fairly straight forward, no additional setup is required. I found only one SPI device is available in user space. This meant that only the pins marked spi1 (P9 header, pins 28- 31) worked in the following code example:
<code>
#include "DigitalInput.h"
#include "DigitalOutput.h"
#include "AnalogOutput.h"
#include "unistd.h"
#include "SPI.h"

using namespace std;

int main() {


	SPI jointencoder;


	jointencoder.open(2,0);

	printf("Encoder open \n");
	jointencoder.setSpeed(1000000);
	printf("speed set \n");
	uint8_t readbuf[2];

	while(1)
	{
		jointencoder.read(readbuf, 2);
		int read = 0;
		read = readbuf[1]+readbuf[0]*255 + 2*(readbuf[1]&128);
		read =(read & 65472);
		read = read >> 5;
		//printf("joint encoder %d \n", read);

	}
<code>

I hope this helps implement your SPI application, as the library is a little difficult to decipher as it works using ioctl calls.

cheers

Peter
