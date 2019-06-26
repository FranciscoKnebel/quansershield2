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
 * @file modules/h_bridge.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Module containing H-bridge function helpers and manipulators.
 */

#include <h_bridge.h>

/**
 * @brief Disable the H-bridge, on GPIO38.
 */
int h_bridge_disable() { return pputs("/sys/class/gpio/gpio38/value", "0"); }

/**
 * @brief Enable the H-bridge, on GPIO38.
 */
int h_bridge_enable() { return pputs("/sys/class/gpio/gpio38/value", "1"); }