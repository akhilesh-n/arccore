/*
 * Configuration of module Pwm (Pwm_Cfg.c)
 *
 * Created by: Arccore AB
 * Configured for (MCU): HCS12
 *
 * Module vendor: ArcCore
 * Module version: 2.0.1
 *
 * 
 * Generated by Arctic Studio (http://arccore.com) 
 *           on Mon Jan 17 08:38:47 CET 2011
 */


#include "Pwm.h"

const Pwm_ConfigType PwmConfig =
{
		.channels = { 		
			{
				.channel =  PWM_CHANNEL_1,
				DUTY_AND_PERIOD(24576,188.0),
				.centerAlign =  STD_OFF,
				.polarity = POLARITY_NORMAL,
				.scaledClockEnable = STD_ON,
				.idleState = PWM_LOW,
				.class = PWM_VARIABLE_PERIOD
			},
		},
		.busPrescalerA = PRESCALER_128,
		.busPrescalerB = PRESCALER_2,
		.prescalerA = 1,
		.prescalerB = 1,
};