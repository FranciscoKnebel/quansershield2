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
 * @file quanser_pwm.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Receive a duty cycle for PWM and enable it.
 */

#include <quanser_pwm.h>

int main(int argc, char const *argv[]) {
  int duty_cycle = 0;

  if (argc < 2) {
    fprintf(stderr, "Usage: ./quanser_pwm <duty_cycle> ");
    exit(1);
  }

  sscanf(argv[1], "%d", &duty_cycle);

  while (1) {
    usleep(TIME_STEP);

    pwm_set_period(PWM_PERIOD);
    pwm_enable();
    pwm_set_duty_cycle(duty_cycle);
    usleep(TIME_STEP);
    pwm_disable();
  }

  return 0;
}
