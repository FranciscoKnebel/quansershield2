/**
 * @file arm.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Header for the arm module, containing arm function helpers and
 * manipulators.
 */

#ifndef ARM_H_
#define ARM_H_

#include <galileo2io.h>
#include <stdio.h>

  int detect_endoftrajectory_elbow(int index);
  int detect_endoftrajectory_shoulder(int index);
  int read_arm(int i);

#endif
