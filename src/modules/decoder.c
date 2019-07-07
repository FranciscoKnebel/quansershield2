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
 * @file modules/decoder.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Module containing dec helper functions.
 */

#include <decoder.h>
#define PI 3.14159265358979323846

struct timespec sleep_time, end_time;

int save(int index, int gpio, char* str) {
  char value[1];
  char gpio_file[50];
  sprintf(gpio_file, "/sys/class/gpio/gpio%d/value", gpio);

  pgets(value, 1, gpio_file);
  str[index] = value[0];

  return index;
}

void reset_decoder() {
  printf("Resetting decoder.\n");
  pputs("/sys/class/gpio/gpio5/value", "0");
  xsleep(1);
  printf("Reset done.\n");
  pputs("/sys/class/gpio/gpio5/value", "1"); // set ~rst to 1 = not reset
}

int read_gpio() {
  char bin[17];
  int gpio[8] = { 13, 6, 0, 1, 38, 40, 4, 10 };
  int counter = 0;
  size_t i;

  // printf("STARTING HIGH!\n");
  pputs("/sys/class/gpio/gpio7/value", "0"); // set sel
  xsleep(1);
  pputs("/sys/class/gpio/gpio15/value", "1"); // oe
  xsleep(5);

  for (i = 0; i < 16; i++) {
    if (i < 8) {
      // HIGH
      save(i, gpio[i], bin);
    } else {
      // LOW
      if (i == 8) {
        // printf("STARTING LOW!\n");
        pputs("/sys/class/gpio/gpio7/value", "1"); // set sel
        xsleep(5);
      }
      save(i, gpio[i-8], bin);
    }
    xsleep(1);
  }

  bin[16] = '\0';
  printf("Counted in Binary: %s.\n", bin);
  counter = strtol(&bin, NULL, 2);
  printf("Counted in Decimal: %d\n", counter);

  pputs("/sys/class/gpio/gpio15/value", "0"); // oe
  xsleep(1);

  return counter;
}

void xsleep(int times) {
  int count = 0;

  while (count < times) {
    nanosleep(&sleep_time,&end_time);
    count++;
  }
}

int read_decoder() {
  int counted = 0;
  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 125000000; //1000 ns = 1 us

  // reset_decoder();

  // printf("================================\n");
  // printf("LENDO RESETADO!\n");
  // counted = read_gpio();
  // printf("================================\n");
  // xsleep(100);

  counted = read_gpio();

  return counted;
}

int counted_to_radians(int counted) {
  int degrees = 0;
  int radians = 0;
  int x = 4; // tipo de contagem
  int n = 1024; // linhas por revolucao

  degrees = (counted*360)/(x*n) % 360;
  radians = (degrees*PI)/(180);

  printf("%d %d %d counted degrees radians\n", counted, degrees, radians);

  return radians;
}
