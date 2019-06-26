// Quanser Shield
// Copyright (C) 2018 Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
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
 * @date 11 Dez 2018
 * @brief Module containing PWM helper functions.
 */

#include <pwm.h>
char str[100];

/**
 * @brief Enable PWM3.
 */
int pwm_enable() { return pputs("/sys/class/pwm/pwmchip0/pwm3/enable", "1"); }

/**
 * @brief Disable PWM3.
 */
int pwm_disable() { return pputs("/sys/class/pwm/pwmchip0/pwm3/enable", "0"); }

/**
 * @brief Set the period on the PWM device.
 */
int pwm_set_period(int period) {
  sprintf(str, "%d", (int)period);
  return pputs("/sys/class/pwm/pwmchip0/device/pwm_period", str);
}

/**
 * @brief Set the duty cycle for PWM3.
 */
int pwm_set_duty_cycle(int duty_cycle) {
  sprintf(str, "%d", duty_cycle);

  return pputs("/sys/class/pwm/pwmchip0/pwm3/duty_cycle", str);
}
