// Quanser Shield v.2
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
 * @file modules/signal_module.c
 * @author Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
 * @date 06 Jul 2019
 * @brief Module containing H-bridge function helpers and manipulators.
 */

#include <signal_module.h>

int (*cb)() = NULL;

/**
 * @brief Standard handling for all signals. Will be called on SIGINT, SIGTERM and SIGKILL.
 * Will call callback defined by program, if defined.
 */

void handle_signal(int signal) {
  int response = 0;
  printf("Signal received: %d. Quitting program...", signal);

  if (cb != NULL) {
    response = cb(signal);
  }
  exit(response);
}

/**
 * @brief Define functions to use if program detects termination signals.
 */
void handle_termination(int (*callback)()) {
  cb = callback;

  signal(SIGINT, handle_signal);
  signal(SIGTERM, handle_signal);
  signal(SIGKILL, handle_signal);
}
