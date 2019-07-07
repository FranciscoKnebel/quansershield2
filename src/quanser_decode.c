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
 * @file quanser_decode.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Receive a duty cycle for PWM and enable it.
 */

 #include <quanser_pwm.h>
 #include <decoder.h>
 #include <time.h>

 int end(int sig) {
   printf("Ending 'quanser_decode.c'\n");

   pwm_disable();
   h_bridge_disable();

   return 0;
 }

 int main(int argc, char const *argv[]) {
   float voltage = 0.0;
   int duty_cycle = 0;
   int period = 0;

   if (argc < 2) {
     fprintf(stderr, "Usage: ./quanser_decode <voltage:int> ");
     exit(1);
   }
   handle_termination(&end);

   voltage = strtol(argv[1], NULL, 10);
   period = calculate_period();

   int counter = read_decoder();
   int radians = counted_to_radians(counter);
   printf("radians: %d\n", radians);
   usleep(TIME_STEP);

   pwm_set_period(period);
   h_bridge_enable();
   pwm_enable();

   duty_cycle = calculate_duty_cycle(voltage, period);
   pwm_set_duty_cycle(duty_cycle);

   struct timespec sleep_time, end_time;
   sleep_time.tv_sec = 1;
   sleep_time.tv_nsec = 0; //1000 ns = 1 us
   nanosleep(&sleep_time, &end_time);
   h_bridge_disable();
   pwm_disable();
   
   // printf("dormindo filho da puta\n");
   // usleep(TIME_STEP);
   printf("LENDO DECODER NOVAMENTE\n");
   counter = read_decoder();
   radians = counted_to_radians(counter);
   printf("radians: %d\n", radians);

   return 0;
 }
