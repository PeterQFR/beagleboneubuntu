beagleboneubuntu
================

Beaglebone libraries created for use with ubuntu

What this is?

This library is a library written in C++ for use with the beaglebone A6 variant. Its been tested on this device an allows access to DigitalIO, AnalogIO, SPI and soon I2C. It can be freely downloaded and used without any warranty expressed or implied. 

DigitalIO.

The DigitalIO allows digital input and digital output for any pin on the P8 or P9 header. It uses the filesystem to access the pins. The pin first must be declared and initialised but prior to use must call openDigitalInput() or openDigitalOutput() and specify the pin that digitalIO function applies to. The pin is identified by the header number and pin number in the header e.g.

DigitalInput pin = new DigitalInput();
pin.openDigitalInput(8, 43);

will initialise and open pin 43 on header 8 as a digital input. 

The pin is polled by calling pin.read() and returns an integer equivalent to the voltage on the pin.

Other methods for DigitalInput and DigitalOutput allow the changing of polarity for the pin.

AnalogIO

The AnalogIO uses the file system to achieve analogOutput (or PWM) on one of the beaglebone's 8 PWM modules. Or to read one of the 6 ADCs.

To setup 
