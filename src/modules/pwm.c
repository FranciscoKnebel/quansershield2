// Quanser Shield v.2
// Copyright (C) 2019 Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

/**
 * @file modules/pwm.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Module containing PWM helper functions.
 */

#include <pwm.h>
#include <h_bridge.h>
char str[100];

/**
 * @brief Enable PWM1.
 */
int pwm_enable() { 
  printf("Enabling PWM...\n");
  return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "1");
}

/**
 * @brief Disable PWM1.
 */
int pwm_disable() {
  printf("Disabling PWM...\n");
  return pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "0");
}

/**
 * @brief Set the period on the PWM device.
 */
int pwm_set_period(int period) {
  sprintf(str, "%d", (int)period);
  printf("Setting pwm period to %s.\n", str);
  return pputs("/sys/class/pwm/pwmchip0/device/pwm_period", str);
}

/**
 * @brief Set the duty cycle for PWM1.
 */
int pwm_set_duty_cycle(int duty_cycle) {
  sprintf(str, "%d", duty_cycle);
  printf("Setting duty cycle to %s.\n", str);  
  return pputs("/sys/class/pwm/pwmchip0/pwm1/duty_cycle", str);
}

/**
 * @brief Set PWM values of period and duty cycle, enabling it and the h_bridge.
 */
int set_pwm(int period, int duty_cycle){
  pwm_set_period(period);
  pwm_set_duty_cycle(duty_cycle);

  pwm_enable();
  h_bridge_enable();
}

/**
 * @brief Calculate period from FREQ_MAX.
 */
int calculate_period() {
  int toNanoSeconds = 1000000000;
  int period = (int)((1.0/FREQ_MAX)*toNanoSeconds);
  
  return period;
}

/**
 * @brief Calculate duty cycle, according to voltage, period and VOLT_MAX.
 */
int calculate_dutycycle(int voltage, int period) {
  int duty_cycle = (int)(voltage/VOLT_MAX*period*0.5 + 0.5*period);

  return duty_cycle;
}