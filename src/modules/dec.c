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
 * @file modules/dec.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Module containing dec helper functions.
 */

#include <dec.h>
#define PI 3.14159265358979323846


int read_decoder(){

  char data[2];
  int counted = 0;
  struct timespec sleep_time;

  sleep_time.tv_sec = 0;
  sleep_time.tv_nsec = 84; //1000 ns = 1 us

  // HIGH BYTE
  pputs("/sys/class/gpio/gpio15/value", "0") // set oe
  pputs("/sys/class/gpio/gpio7/value", "0") // set sel
  nanosleep(&sleep_time,NULL);

  pgets(data, 2, "/sys/class/gpio/gpio13/value");
  counted += atoi(data)*32768;
  pgets(data, 2, "/sys/class/gpio/gpio6/value");
  counted += atoi(data)*16384;
  pgets(data, 2, "/sys/class/gpio/gpio0/value");
  counted += atoi(data)*8192;
  pgets(data, 2, "/sys/class/gpio/gpio1/value");
  counted += atoi(data)*4096;
  pgets(data, 2, "/sys/class/gpio/gpio38/value");
  counted += atoi(data)*2048;
  pgets(data, 2, "/sys/class/gpio/gpio40/value");
  counted += atoi(data)*1024;
  pgets(data, 2, "/sys/class/gpio/gpio4/value");
  counted += atoi(data)*512;
  pgets(data, 2, "/sys/class/gpio/gpio10/value");
  counted += atoi(data)*256;

  // LOW BYTE
  pputs("/sys/class/gpio/gpio7/value", "1") // set sel
  nanosleep(&sleep_time,NULL);

  pgets(data, 2, "/sys/class/gpio/gpio13/value");
  counted += atoi(data)*128;
  pgets(data, 2, "/sys/class/gpio/gpio6/value");
  counted += atoi(data)*64;
  pgets(data, 2, "/sys/class/gpio/gpio0/value");
  counted += atoi(data)*32;
  pgets(data, 2, "/sys/class/gpio/gpio1/value");
  counted += atoi(data)*16;
  pgets(data, 2, "/sys/class/gpio/gpio38/value");
  counted += atoi(data)*8;
  pgets(data, 2, "/sys/class/gpio/gpio40/value");
  counted += atoi(data)*4;
  pgets(data, 2, "/sys/class/gpio/gpio4/value");
  counted += atoi(data)*2;
  pgets(data, 2, "/sys/class/gpio/gpio10/value");
  counted += atoi(data)*1;

  pputs("/sys/class/gpio/gpio15/value", "1") // set oe

  return counted;
}

int counted_to_radians(int counted){

  int degrees = 0;
  int radians = 0;
  int x = 4; //tipo de contagem
  int n = 1024; //linhas por revolucao

  degrees = (counted*360)/(x*n);

  radians = (degrees*PI)/(180);

  return radians;
}