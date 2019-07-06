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
 * @file modules/signal_module.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 06 Jul 2019
 * @brief Module containing H-bridge function helpers and manipulators.
 */
#include <signal_module.h>

void handle_SIGINT(int signal) {
  printf("Signal received for SIGINT: %d\n", signal);
}

void handle_SIGTERM(int signal) {
  printf("Signal received for SIGTERM: %d\n", signal);
}

void handle_SIGKILL(int signal) {
  printf("Signal received for SIGKILL: %d\n", signal);
}

/**
 * @brief Define functions to use if program detects termination signals.
 */
void handle_termination_signals() {
  signal(SIGINT, handle_SIGINT);
  signal(SIGTERM, handle_SIGTERM);
  signal(SIGKILL, handle_SIGKILL);
}
