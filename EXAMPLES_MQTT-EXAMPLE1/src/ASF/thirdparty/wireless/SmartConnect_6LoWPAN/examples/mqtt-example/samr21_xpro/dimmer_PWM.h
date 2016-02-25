/*
 * dimmer_PWM.h
 * Created: 24/02/2016 19:51:08
 * Author: Yuri A. Rodrigues
 * Company: AWGES
 */


#ifndef DIMMER_PWM_
#define DIMMER_PWM_

#include "tcc.h"


//[definition_pwm]
/** PWM module to use */
#define CONF_PWM_MODULE      LED_0_PWM4CTRL_MODULE
/** PWM channel */
#define CONF_PWM_CHANNEL     LED_0_PWM4CTRL_CHANNEL
/** PWM output */
#define CONF_PWM_OUTPUT      LED_0_PWM4CTRL_OUTPUT
/** PWM output pin */
#define CONF_PWM_OUT_PIN     LED_0_PWM4CTRL_PIN
/** PWM output pinmux */
#define CONF_PWM_OUT_MUX     LED_0_PWM4CTRL_MUX
//[definition_pwm]


void pwm_init(void);

void conf_duty_cicle(uint32_t i);

#endif /* INCFILE1_H_ */