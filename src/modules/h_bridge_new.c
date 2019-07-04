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
 * @file modules/h_bridge.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Module containing H-bridge function helpers and manipulators.
 */

#include <h_bridge_new.h>

/**
 * @brief Disable the H-bridge, on GPIO.
 */
int h_bridge_disable_left() { return pputs("/sys/class/gpio/gpio11/value", "0"); }
int h_bridge_disable_right() { return pputs("/sys/class/gpio/gpio12/value", "0"); }

/**
 * @brief Enable the H-bridge, on GPIO.
 */
int h_bridge_enable_left() { return pputs("/sys/class/gpio/gpio11/value", "1"); }
int h_bridge_enable_right() { return pputs("/sys/class/gpio/gpio12/value", "1"); }