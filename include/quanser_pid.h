/**
 * @file quanser_controller.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 */

#ifndef QUANSER_PID_H
#define QUANSER_PID_H

#include <decoder.h>
#include <pwm.h>
#include <spi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIME_STEP 10000
#define PWM_PERIOD 1500000

#define MAX_VOLTAGE 27
#define MIN_VOLTAGE (-27)

#define DUTY_SLOPE PWM_PERIOD / (MAX_VOLTAGE - MIN_VOLTAGE)
#define DUTY_LIMIT DUTY_SLOPE *MAX_VOLTAGE

int main(int argc, char *argv[]);

#endif
