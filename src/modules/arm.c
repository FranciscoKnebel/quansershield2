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
 * @file modules/arm.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Module containing arm helper functions.
 */

#include <arm.h>

/**
 * @brief Detect if reached end of trajectory in 'index' elbow.
 */
int detect_endoftrajectory_elbow(int index) {
  if (index > 2 || index < 1) {
    return -1;
  }

  return read_arm(index) == 0;
}

/**
 * @brief Detect if reached end of trajectory in 'index' shoulder.
 */
int detect_endoftrajectory_shoulder(int index)
{
  index += 2;

  if(index > 4 || index < 3) {
    return -1;
  }
  return read_arm(index) == 0;
}

/**
 * @brief Read value of arm element and returns if finished (0) or  not (1)
 */
int read_arm(int i) {
  char buffer[1];

  switch(i) {
    case 1: // elbow 1
      pgets(buffer, 1, "/sys/class/gpio/gpio13/value");
      break;
    case 2: // elbow 2
      pgets(buffer, 1, "/sys/class/gpio/gpio14/value");
      break;
    case 3: // shoulder 1
      pgets(buffer, 1, "/sys/class/gpio/gpio9/value");
      break;
    case 4: // shoulder 2
      pgets(buffer, 1, "/sys/class/gpio/gpio1/value");
      break;
  }

  int finished;
  sscanf(buffer, "%d", &finished);

  return finished;
}
