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
#define VOLT_MAX 12 // ALTERAR PARA 27 PARA O TRABALHO

int main(int argc, char const *argv[]) {
  float voltage = 0.0;
  float voltage_abs = 0.0;
  int duty_cycle = 0;
  int period = 0;
  if (argc < 2) {
    fprintf(stderr, "Usage: ./quanser_pwm <voltage:int> ");
    exit(1);
  }
  voltage = strtol(argv[1], NULL, 10);
  voltage_abs = voltage;
  period = (int)((1.0 /FREQ_MAX)*1000000000);
  duty_cycle = (int)(voltage_abs/VOLT_MAX*period*0.5 + 0.5*period);

  // while (1) {
    usleep(TIME_STEP);

    pwm_set_period(period);
    pwm_set_duty_cycle(duty_cycle);
    pwm_enable();

    h_bridge_enable();
    /*if (voltage > 0) {
      h_bridge_enable_right();
    } else if (voltage < 0){
      h_bridge_enable_left();
    } else {
      h_bridge_disable_left();
      h_bridge_disable_right();
    }*/
  // }

  return 0;
}

// catch CTRL+C and pwm_disable()
