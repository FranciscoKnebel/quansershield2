/**
 * @file quanser_motor.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 */

#ifndef QUANSER_MOTOR_H
#define QUANSER_MOTOR_H

#include <h_bridge.h>
#include <pwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIME_STEP 10000
#define PWM_PERIOD 1500000

#define MAX_VOLTAGE 27
#define MIN_VOLTAGE (-27)

#define DUTY_SLOPE PWM_PERIOD / (MAX_VOLTAGE - MIN_VOLTAGE)
#define DUTY_LIMIT DUTY_SLOPE *MAX_VOLTAGE

#endif
