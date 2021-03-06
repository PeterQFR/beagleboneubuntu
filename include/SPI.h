/*
 * This Library was copied from prianna32's library on github https://github.com/piranha32/IOoo.git
 * SPI.h
 *
 *  Created on: Jun 2, 2013
 *      Author: jacek
 */
/*
 * For use on the original beaglebone, A6. The user space SPI module is marked SPI1_0 on the pin outs. Therefore
 * when the spi module is run it seems to only work on pins 28, 30, 32 in header 9. The pins in the 16-18 pin range
 * are not available. No other setup of the pins is required.
 */


#include <stdint.h>
#include <linux/spi/spidev.h>

#include "iopin.h"

#ifndef SPI_H_
#define SPI_H_

class SPI
{
	private:
		iopin MISO, MOSI, CS, CLK;
		uint8_t mode;
		uint8_t bpw;
		bool lsb_first;
		uint32_t speed;
		bool active;
		int fd;
	public:

		/**
		 * Default constructor for SPI class.
		 */
		SPI();

		/**
		 * Function opens the SPI device.
		 * @param bus
		 * @param channel
		 * @return
		 */
		int open(int bus, int channel);

		/**
		 * Function closes the SPI device.
		 * @return
		 */
		int close();

		/**
		 * Functions sets the idle level and active edge of the clock signal.
		 * @param mode
		 * @return
		 */
		int setMode(uint8_t mode);

		/**
		 * Function sets idle level for the clock signal.
		 * @param pol
		 * @return
		 */
		int setClockPolarity(uint8_t pol);

		/**
		 *  Function sets active edge for the clock signal.
		 * @param phase
		 * @return
		 */
		int setClockPhase(uint8_t phase);

		/**
		 * Function sets order of bits in transmitted data.
		 * @param lsb_first
		 * @return
		 */
		int setLSBFirst(bool lsb_first);

		/**
		 * Function sets the number of bits per transferred word.
		 * @param bits
		 * @return
		 */
		int setBitsPerWord(int bits);

		/**
		 * Function set the speed of the SPI interface.
		 * @param speed
		 * @return
		 */
		int setSpeed(uint32_t speed);


		/**
		 * Method writes len bytes to the device.
		 * @param wbuf
		 * @param len
		 * @return
		 */
		int write(uint8_t wbuf[], int len);

		/**
		 * Method reads len bytes from the device.
		 * @param rbuf
		 * @param len
		 * @return
		 */
		int read(uint8_t rbuf[], int len);

		/**
		 * Function performs simultaneous read and write on the device.
		 * @param wbuf
		 * @param rbuf
		 * @param len
		 * @return
		 */
		int xfer1(uint8_t wbuf[], uint8_t rbuf[], int len);

		/**
		 *
		 */
		virtual ~SPI();
};

#endif /* SPI_H_ */
