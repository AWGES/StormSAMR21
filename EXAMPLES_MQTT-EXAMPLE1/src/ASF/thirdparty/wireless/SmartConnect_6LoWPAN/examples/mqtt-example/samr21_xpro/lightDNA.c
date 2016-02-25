/*
* LightDNA.c
*
* Created: 22/02/2016 17:33:51
* Author: Yuri A. Rodrigues
* Company: AWGES
*/

/**
* \brief Function for configuring I2C master
*
* This function will configure the I2C master module with
* the light dimmer controller
*/


#include "lightDNA.h"

int configure_i2c_light(void)
{
	/* Initialize config structure and software module. */
	struct i2c_master_config config_i2c_master;		i2c_master_get_config_defaults(&config_i2c_master);
	/* Change buffer timeout to something longer. */

	/* Change pins */
	config_i2c_master.pinmux_pad0  = PINMUX_PA16C_SERCOM1_PAD0;
	config_i2c_master.pinmux_pad1  = PINMUX_PA17C_SERCOM1_PAD1;
	

	config_i2c_master.buffer_timeout = 10000;
	/* Initialize and enable device with config. */
	i2c_master_init(&i2c_master_instance, CONF_I2C_MASTER_MODULE,
	&config_i2c_master);
	i2c_master_enable(&i2c_master_instance);		return init_i2c_light();
}

int init_i2c_light (void){
	
	int timeout=0;
	uint8_t testes[2];
	master_packet.address         = DIMMER_LIGHT_I2C_ADDR;
	master_packet.data_length     = 0x02;
	master_packet.data            = testes;
	master_packet.ten_bit_address = false;
	master_packet.high_speed      = false;
	master_packet.hs_master_code  = 0x0;
	
	/* Write buffer to slave until success. */
	while (i2c_master_write_packet_wait(&i2c_master_instance, &master_packet) !=
	STATUS_OK) {
		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			return NOK;
		}
	}
	return OK;
}

int read_dimmer(uint8_t command){
	int result = 0;
	int timeout = 0;
	
	uint8_t reciever_buffer[6];
	reciever_buffer[0] = 0x03;
	master_packet.address         = DIMMER_LIGHT_I2C_ADDR;
	master_packet.data_length     = 0x01;
	master_packet.data            = reciever_buffer;
	master_packet.ten_bit_address = false;
	master_packet.high_speed      = false;
	master_packet.hs_master_code  = 0x0;
	
	while (i2c_master_write_packet_wait(&i2c_master_instance, &master_packet) !=
	STATUS_OK) {

		/* Increment timeout counter and check if timed out. */
		if (timeout++ == TIMEOUT) {
			break;
		}
	}
	master_packet.data_length     = 6;
	master_packet.data            = reciever_buffer;
	while (i2c_master_read_packet_wait(&i2c_master_instance, &master_packet) !=
	STATUS_OK) {
		//printf("timeout: %d || TIMEOUT \n\r",timeout);
		/* Increment timeout counter and check if timed out. */
		if (timeout++ > TIMEOUT) {
			
			timeout = 0;
			break;
		}
	}
	result = reciever_buffer[0]<<8;
	result |=reciever_buffer[1];
	printf("x: %d\n\r",result);
	
	return result;
}