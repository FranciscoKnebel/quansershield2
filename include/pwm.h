/**
 * @file pwm.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Header for the PWM module, containing PWM function helpers and
 * manipulators.
 */

#ifndef PWM_H_
#define PWM_H_

#include <galileo2io.h>
#include <stdio.h>

int pwm_enable();
int pwm_disable();
int pwm_set_period(int period);
int pwm_set_duty_cycle(int pwm_set_duty_cycle);
int set_pwm(int period, int duty_cycle);

#endif
