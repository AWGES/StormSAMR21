/*
 * LightDNA.h
 *
 * Created: 22/02/2016 17:36:31
 * Author: Yuri A. Rodrigues
 * Company: AWGES
 */ 

#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "samr21_xplained_pro/samr21_xplained_pro.h"
#include "i2c_master.h"
#include "i2c_common.h"
#define CONF_I2C_MASTER_MODULE    SERCOM1

#define DIMMER_LIGHT_I2C_ADDR			0x1E
#define TIMEOUT							1000
#define OK								0
#define NOK								-1
/* Configure the I2C master module */
int init_i2c_light(void);

/* Configure the I2C master module */
int configure_i2c_light(void);

/* Simple read */
int read_dimmer(uint8_t command);		//it is a example read firstly an accelerometer and after will read the real dimmer

struct i2c_master_module i2c_master_instance;
struct i2c_master_packet master_packet;

#endif /* INCFILE1_H_ */