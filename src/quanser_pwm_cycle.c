// Quanser Shield v.2
// Copyright (C) 2019 Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
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
 * @file quanser_pwm_cycle.c
 * @author Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Program to cycle through PWM.
 */

#include <quanser_pwm.h>

int end(int sig) {
  printf("Ending 'quanser_pwm_cycle.c'\n");

  pwm_disable();
  h_bridge_disable();

  return 0;
}

int main(int argc, char const *argv[]) {
  float voltage = 0.0;
  int duty_cycle = 0;
  int period = 0;
  int direction;

  handle_termination(&end);
  detect_endoftrajectory();

  period = calculate_period();
  pwm_set_period(period);
  pwm_enable();
  h_bridge_enable();

  voltage = -VOLT_MAX;
  direction = 1;
  while (1) {
    voltage += 1 * direction;
    duty_cycle = calculate_duty_cycle(voltage, period);
    pwm_set_duty_cycle(duty_cycle);
    usleep(TIME_STEP);

    if (fabs(voltage) > VOLT_MAX) {
      printf("chegou a max velocidade: %f\n", voltage);
      direction *= -1;
    }
  }

  return 0;
}
