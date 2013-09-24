/*
 * iopin.cpp
 *
 *  Created on: 05/08/2013
 *      Author: petermilani
 */
#include "iopin.h"

iopin::iopin()
{

}

char* iopin::getGPIONumber()
{
	return gpiono;
}
/**
	 * This function allows the establishment of a pin depending on its bank and pin number as well
	 * as its mode. The operator is required to ensure the details are correct.
	 * bank - either 8 or 9
	 * pin - 1 to 46
	 * mode - 0 to 7
	 */
void iopin::openPin(int bank, int pin, int mode, bool pullup, bool input)
{


	Mux_dir = "/sys/kernel/debug/omap_mux/";

	//cout << "Mux_dir_set " << Mux_dir << endl;
	validpin = true;

	if (bank ==8)
	{
		if((pin<3)||(pin>46))
		{
			printf("ERROR: invalid pin %i selected in header %i \n", pin, bank);
			validpin = false;
		}

		switch (pin)
		{
		case 3:
			Name = "gpmc_ad6";
			gpiono = "38";
			break;
		case 4:
			Name = "gpmc_ad7";
			gpiono = "39";
			break;
		case 5:
			Name = "gpmc_ad2";
			gpiono = "34";
			break;
		case 6:
			Name = "gpmc_ad3";
			gpiono = "35";
			break;
		case 7:
			Name = "gpmc_advn_ale";
			gpiono = "66";
			break;
		case 8:
			Name = "gpmc_oen_ren";
			gpiono = "67";
			break;
		case 9:
			Name = "gpmc_be0n_cle";
			gpiono = "69";
			break;
		case 10:
			Name = "gpmc_wen";
			gpiono = "68";
			break;
		case 11:
			Name = "gpmc_ad13";
			gpiono = "45";
			break;
		case 12:
		 	 Name = "gpmc_ad12";
		 	gpiono = "44";
		 	 break;
		case 13:
			Name = "gpmc_ad9";
			gpiono = "23";
			break;
		case 14:
			Name = "gpmc_ad10";
			gpiono = "26";
			break;
		case 15:
			Name = "gpmc_ad15";
			gpiono = "47";
			break;
		case 16:
			Name = "gpmc_ad14";
			gpiono = "46";
			break;
		case 17:
			Name = "gpmc_ad11";
			gpiono = "27";
			break;
		case 18:
			Name = "gpmc_clk_mux0";
			gpiono = "65";
			break;
		case 19:
			Name = "gpmc_ad8";
			gpiono = "22";
			break;
		case 20:
			Name = "gpmc_csn2";
			gpiono = "63";
			break;
		case 21:
			Name = "gpmc_csn1";
			gpiono = "62";
			break;
		case 22:
			Name = "gpmc_ad5";
			gpiono = "37";
			break;
		case 23:
			Name = "gpmc_ad4";
			gpiono = "36";
			break;
		case 24:
			Name = "gpmc_ad1";
			gpiono = "33";
			break;
		case 25:
			Name = "gpmc_ad0";
			gpiono = "32";
			break;
		case 26:
			Name = "gpmc_csn0";
			gpiono = "61";
			break;
		case 27:
			Name = "lcd_vsync";
			gpiono = "86";
			break;
		case 28:
			Name = "lcd_pclk";
			gpiono = "88";
			break;
		case 29:
			Name = "lcd_hsync";
			gpiono = "87";
			break;
		case 30:
			Name = "lcd_ac_bias_en";
			gpiono = "89";
			break;
		case 31:
			Name = "lcd_data14";
			gpiono = "10";
			break;
		case 32:
			Name = "lcd_data15";
			gpiono = "11";
			break;
		case 33:
			Name = "lcd_data13";
			gpiono = "9";
			break;
		case 34:
			Name = "lcd_data11";
			gpiono = "81";
			break;
		case 35:
			Name = "lcd_data12";
			gpiono = "8";
			break;
		case 36:
			Name = "lcd_data10";
			gpiono = "80";
			break;
		case 37:
			Name = "lcd_data8";
			gpiono = "78";
			break;
		case 38:
			Name = "lcd_data9";
			gpiono = "79";
			break;
		case 39:
			Name = "lcd_data6";
			gpiono = "76";
			break;
		case 40:
			Name = "lcd_data7";
			gpiono = "77";
			break;
		case 41:
			Name = "lcd_data4";
			gpiono = "74";
			break;
		case 42:
			Name = "lcd_data5";
			gpiono = "75";
			break;
		case 43:
			Name = "lcd_data2";
			gpiono = "72";
			break;
		case 44:
			Name = "lcd_data3";
			gpiono = "73";
			break;
		case 45:
			Name ="lcd_data0";
			gpiono = "70";
			break;
		case 46:
			Name = "lcd_data1";
			gpiono = "71";
			break;


		}




	}
	else if (bank == 9)
	{
		if ((pin<11)||(pin>42))
		{
			printf("ERROR: Invalid Pin %i selected in Header %i \n", pin, bank);
			validpin= false;
		}
		else
		{
			if((pin>31)&&(pin<40))
			{
				printf("ERROR: Invalid GPIO pin, if you want ADC see openAnalogInput \n");
				validpin = false;
			}

		}


		switch (pin)
		{
		case 11:
			Name = "gpmc_wait0";
			gpiono = "30";
			break;
		case 12:
			Name = "gpmc_be1n";
			gpiono = "60";
			break;
		case 13:
			Name = "gpmc_wpn";
			gpiono = "31";
			break;
		case 14:
			Name = "gpmc_a2";
			gpiono = "50";
			break;
		case 15:
			Name = "gpmc_a0";
			gpiono = "48";
			break;
		case 16:
			Name = "gpmc_a3";
			gpiono = "51";
			break;
		case 17:
			Name = "spi0_cs0";
			gpiono = "5";
			break;
		case 18:
			Name = "spi0_d1";
			gpiono = "4";
			break;
		case 19:
			Name = "uart1_rtsn";
			gpiono = "13";
			break;
		case 20:
			Name = "uart1_ctsn";
			gpiono = "12";
			break;
		case 21:
			Name = "spi0_d0";
			gpiono = "3";
			break;
		case 22:
			Name = "spi0_sclk";
			gpiono = "2";
			break;
		case 23:
			Name = "gpmc_a1";
			gpiono = "49";
			break;
		case 24:
			Name = "uart1_txd";
			gpiono = "15";
			break;
		case 25:
			Name = "mcasp0_ahclkx";
			gpiono = "117";
			break;
		case 26:
			Name = "uart1_rxd";
			gpiono = "14";
			break;
		case 27:
			Name = "mcasp0_fsr";
			gpiono = "115";
			break;
		case 28:
			Name = "mcasp0_ahclkr";
			gpiono = "113";
			break;
		case 29:
			Name = "mcasp0_fsx";
			gpiono = "111";
			break;
		case 30:
			Name = "mcasp0_axr0";
			gpiono = "112";
			break;
		case 31:
			Name = "msasp0_aclkx";
			gpiono = "110";
			break;
		case 41:
			Name = "xdma_event_intr1";
			gpiono = "20";
			break;
		case 42:
			Name = "eCAP0_in_PWM0_out";
			gpiono = "7";
			break;

		}
	}


	if (validpin)
	{
		char *basic;
		if (input)
		{
			if (pullup)
			{
				basic ="3";
			}
			else if (!pullup)
			{
				basic="2";
			}
		}
		else if (!input)
		{
			basic="1";
		}
	//cout << "basic initiallised " << basic << endl;

	char c = '0'+  mode;

	//cout << "char converted " << c << endl;
	char muxsettings[2];
	strcpy(muxsettings, basic);
	strcat(muxsettings, &c);


	char muxfilename[80];
	strcpy(muxfilename, Mux_dir);
	strcat(muxfilename, Name);
	cout << "file opened: " << muxfilename << endl;
	//Now open the mux settings file and write the required binary:
	MuxFile = fopen(muxfilename, "r+");

	//cout << "Mux Handle " << MuxFile << endl;

	fwrite(muxsettings, sizeof(char), 2, MuxFile);

	cout << "file written: " << muxsettings << endl;

	fclose(MuxFile);
	}
}

iopin::~iopin()
{

}


