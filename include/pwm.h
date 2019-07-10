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
#include <math.h>

int pwm_enable();
int pwm_disable();
int pwm_set_period(int period);
int pwm_set_duty_cycle(int pwm_set_duty_cycle);
int set_pwm(int period, int duty_cycle);

int calculate_period();
int calculate_duty_cycle(float voltage, int period);

/**
* @brief Time step used in sleep functions.
*/
#define TIME_STEP 10000
/**
* @brief PWM signal period.
*/
#define PWM_PERIOD 1500000

/**
* @brief Frequency used for duty cycle calculation.
*/
#define FREQ_MAX 1500

/**
* @brief Max voltage defineable in user programs.
*/
#define VOLT_MAX 27

#endif
