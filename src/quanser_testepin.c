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
 * @file quanser_testepin.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Receive a gpio pin and tests it.
 */

#include <quanser_pwm.h>

int main(int argc, char const *argv[]){
  char buffer[1];
  int gpios[12] = {13, 6, 0, 1, 38, 40, 4, 10, 52, 54, 48, 50};
  int i = 0;
  int gpio;
  while(1){
    char str[50];
    gpio = gpios[i];
    sprintf(str, "/sys/class/gpio/gpio%d/value", gpio);
    pgets(buffer, 1, str);
    printf("%d waiting\n", gpio);
    if (buffer[0] == '1'){
      printf("%s\n",buffer);
      usleep(TIME_STEP*10);
      i = i+1;
      if (i >= 12){
        return 0;
      }

    }
  }
}
