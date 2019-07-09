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
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @file quanser_trajectory.c
 * @date 26 Jun 2019
 * @brief Detect if end of trajectory of elbows 1 and 2, and shoulders 1 and 2.
 */

#include <quanser_trajectory.h>

int main(int argc, char const *argv[]) {
  detect_endoftrajectory_elbow(1);
  detect_endoftrajectory_elbow(2);

  detect_endoftrajectory_shoulder(1);
  detect_endoftrajectory_shoulder(2);

  while(1);

  return 0;
}
