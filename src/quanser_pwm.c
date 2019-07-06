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

int end(int sig) {
  printf("Ending 'quanser_pwm.c'\n");

  pwm_disable();
  h_bridge_disable();

  return 0;
}

int main(int argc, char const *argv[]) {
  float voltage = 0.0;
  int duty_cycle = 0;
  int period = 0;

  if (argc < 2) {
    fprintf(stderr, "Usage: ./quanser_pwm <voltage:int> ");
    exit(1);
  }

  handle_termination(&end);

  voltage = strtol(argv[1], NULL, 10);
  period = calculate_period();
  duty_cycle = calculate_duty_cycle(voltage, period);

  printf("%f %d %d v p d\n", voltage, period, duty_cycle);

  usleep(TIME_STEP);
  pwm_set_period(period);
  pwm_set_duty_cycle(duty_cycle);
  pwm_enable();
  h_bridge_enable();

  while(1);

  return 0;
}
