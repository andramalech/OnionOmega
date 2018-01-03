// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD7999
// This code is designed to work with the AD7999_I2CADC I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Analog-Digital-Converters?sku=AD7999_I2CADC#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-0";
	if ((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, AD7999 I2C address is 0x29(41)
	ioctl(file, I2C_SLAVE, 0x29);
	

	// Send configuration command(0x10)
	// Channel-1, filter enabled
	char config[1] = {0x10};
	write(file, config, 1);
	sleep(1);

	// Read 2 bytes of data
	// raw_adc msb, raw_adc lsb
	char data[2]={0};
	if(read(file, data, 2) != 2)
	{
		printf("Error : Input/Output Error \n");
	}
	else 
	{
		// Convert the data to 8-bits
		int raw_adc = ((data[0] & 0x0F)  * 256 + (data[1] & 0xF0)) / 16 ;

		// Output data to screen
		printf("Digital Value of Analog Input on Channel-1: %d \n", raw_adc);
	}

	// Send configuration command(0x20)
	// Channel-2, filter enabled
	config[0] = 0x20;
	write(file, config, 1);
	sleep(1);

	// Read 2 bytes of data
	// raw_adc msb, raw_adc lsb
	data[2] = 0;
	if(read(file, data, 2) != 2)
	{
		printf("Error : Input/Output Error \n");
	}
	else 
	{
		// Convert the data to 8-bits
		int raw_adc = ((data[0] & 0x0F)  * 256 + (data[1] & 0xF0)) / 16 ;

		// Output data to screen
		printf("Digital Value of Analog Input on Channel-2: %d \n", raw_adc);
	}

	// Send configuration command(0x40)
	// Channel-3, filter enabled
	config[0] = 0x40;
	write(file, config, 1);
	sleep(1);

	// Read 2 bytes of data
	// raw_adc msb, raw_adc lsb
	memset(data, 0, sizeof(data));
	if(read(file, data, 2) != 2)
	{
		printf("Error : Input/Output Error \n");
	}
	else 
	{
		// Convert the data to 8-bits
		int raw_adc = ((data[0] & 0x0F)  * 256 + (data[1] & 0xF0)) / 16 ;

		// Output data to screen
		printf("Digital Value of Analog Input on Channel-3: %d \n", raw_adc);
	}

	// Send configuration command(0x80)
	// Channel-4, filter enabled
	config[0] = 0x80;
	write(file, config, 1);
	sleep(1);

	// Read 2 bytes of data
	// raw_adc msb, raw_adc lsb
	memset(data, 0, sizeof(data));
	if(read(file, data, 2) != 2)
	{
		printf("Error : Input/Output Error \n");
	}
	else 
	{
		// Convert the data to 8-bits
		int raw_adc = ((data[0] & 0x0F)  * 256 + (data[1] & 0xF0)) / 16 ;

		// Output data to screen
		printf("Digital Value of Analog Input on Channel-4: %d \n", raw_adc);
	}
}
