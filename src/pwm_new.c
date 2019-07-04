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
 * @file quanser_pwm.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Receive a duty cycle for PWM and enable it.
 */

#include <quanser_pwm.h>
#define FREQ_MAX 1500
#define VOLT_MAX 27

int main(int argc, char const *argv[]) {
  int voltage = 0;
  int duty_cycle = 0;
  int period = 0;

  if (argc < 2) {
    fprintf(stderr, "Usage: ./quanser_pwm <voltage> ");
    exit(1);
  }
  voltage = argv[1]
  period = (int)((1.0 /FREQ_MAX)*1000000000);
  duty_cycle = (int)((voltage/VOLT_MAX)*period + 0.5*period);

  666666.666667
  //sscanf(argv[1], "%d", &duty_cycle);

  while (1) {
    usleep(TIME_STEP);

    if (voltage >= 0) {
      pwm_set_period(PWM_PERIOD);
      pwm_set_duty_cycle(duty_cycle);
      pwm_enable_left();
    }
    else {
      pwm_set_period(PWM_PERIOD);
      pwm_set_duty_cycle(duty_cycle);
      pwm_enable_right();
    }

  }

  return 0;
}