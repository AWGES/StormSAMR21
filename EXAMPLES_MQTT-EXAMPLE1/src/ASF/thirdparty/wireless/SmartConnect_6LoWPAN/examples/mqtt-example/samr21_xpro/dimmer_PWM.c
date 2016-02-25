/*
 * dimmer_PWM.c
 * Created: 24/02/2016 19:51:08
 * Author: Yuri A. Rodrigues
 * Company: AWGES
*/
#include <asf.h>

#include "dimmer_PWM.h"
#include "tcc.h"

struct tcc_module tcc_instance;

void pwm_init(void)
{
	struct tcc_config config_tcc;
	tcc_get_config_defaults(&config_tcc, CONF_PWM_MODULE);

	config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV2;
	config_tcc.counter.period = 790;	
	config_tcc.compare.match[CONF_PWM_CHANNEL] = 790;
	config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	config_tcc.pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = true;
	config_tcc.pins.wave_out_pin[CONF_PWM_OUTPUT]        = CONF_PWM_OUT_PIN;
	config_tcc.pins.wave_out_pin_mux[CONF_PWM_OUTPUT]    = CONF_PWM_OUT_MUX;

	tcc_init(&tcc_instance, CONF_PWM_MODULE, &config_tcc);
	tcc_enable(&tcc_instance);
}

void conf_duty_cicle(uint32_t i)
{
	struct tcc_config config_tcc;
	tcc_disable(&tcc_instance);
	tcc_reset(&tcc_instance);

	tcc_get_config_defaults(&config_tcc, CONF_PWM_MODULE);

	config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV2;
	config_tcc.counter.period = 790;	
	config_tcc.compare.match[CONF_PWM_CHANNEL] = i;
	config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	config_tcc.pins.enable_wave_out_pin[CONF_PWM_OUTPUT] = true;
	config_tcc.pins.wave_out_pin[CONF_PWM_OUTPUT]        = CONF_PWM_OUT_PIN;
	config_tcc.pins.wave_out_pin_mux[CONF_PWM_OUTPUT]    = CONF_PWM_OUT_MUX;

	tcc_init(&tcc_instance, CONF_PWM_MODULE,	&config_tcc);
	tcc_enable(&tcc_instance);
}
