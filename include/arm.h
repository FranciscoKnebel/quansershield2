/**
 * @file arm.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Header for the arm module, containing arm function helpers and
 * manipulators.
 */

#ifndef ARM_H_
#define ARM_H_

#include <galileo2io.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <poll.h>
#include <pthread.h>
#include <unistd.h>

#include <pwm.h>
#include <h_bridge.h>

  int detect_endoftrajectory_elbow(int index);
  int detect_endoftrajectory_shoulder(int index);
  void read_arm(int i);
  int read_file_end_of_trajectory(int gpio);
  void detect_endoftrajectory();

#endif
