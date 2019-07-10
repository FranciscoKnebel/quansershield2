\// Quanser Shield v.2
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
 * @file modules/arm.c
 * @author Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
 * @date 26 Jun 2019
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
  read_arm(index);
  return 0;
}

/**
 * @brief Detect if reached end of trajectory in 'index' shoulder.
 */
int detect_endoftrajectory_shoulder(int index) {
  index += 2;

  if(index > 4 || index < 3) {
    return -1;
  }
  read_arm(index);
  return 0;
}

/**
 * @brief Creates threads to detect end of trajectory for elbow or shoulder.
 */
void read_arm(int i) {
  pthread_t thread;

  switch(i) {
    case 1: // elbow 1
      pthread_create(&thread, NULL, &read_file_end_of_trajectory, 52);
      break;
    case 2: // elbow 2
      pthread_create(&thread, NULL, &read_file_end_of_trajectory, 54);
      break;
    case 3: // shoulder 1
      pthread_create(&thread, NULL, &read_file_end_of_trajectory, 48);
      break;
    case 4: // shoulder 2
      pthread_create(&thread, NULL, &read_file_end_of_trajectory, 50);
      break;
  }
}


/**
* @brief Read GPIO file and waits for interrupt, for use with end of trajectory. Disables PWM and H_bridge when reached.
**/
int read_file_end_of_trajectory(int gpio) {
  char str[100];
  unsigned char c;
  struct pollfd pfd;

  sprintf(str, "/sys/class/gpio/gpio%d/value", gpio);
  if((pfd.fd = open(str,O_RDONLY)) < 0) {
    return -1;
  }

  read(pfd.fd, &c, 1);
  pfd.events=POLLPRI;

  printf("Waiting for interrupt from gpio%d...\n", gpio);
  sprintf(str, "/sys/class/gpio/gpio%d/edge", gpio);

  pputs(str, "falling");
  poll(&pfd,1,-1);
  lseek(pfd.fd,0,SEEK_SET);
  read(pfd.fd,&c,1);

  if (c == '0') {
    printf("Chegou ao fim de curso, gpio %d.\n\n", gpio);

    pwm_disable();
    h_bridge_disable();
  }

  pputs(str, "none");
  close(pfd.fd);

  return 0;
}

/**
* @brief Set all threads to detect end of trajectory in both shoulder and elbow.
**/
void detect_endoftrajectory() {
  detect_endoftrajectory_elbow(1);
  detect_endoftrajectory_elbow(2);
  detect_endoftrajectory_shoulder(1);
  detect_endoftrajectory_shoulder(2);
}
