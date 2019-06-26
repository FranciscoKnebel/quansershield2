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
 * @file modules/decoder.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Module for decoder functions and helpers.
 */

#include <decoder.h>

/**
 * @brief Initializes the decoder.
 */
void decoder_init() {
  char wr_data[2] = {WRITE_MDR0, QUADRX1};
  char rd_data[2];
  spi_transfer((uint8_t *)wr_data, (uint8_t *)rd_data);
}

/**
 * @brief Read decoder counter.
 */
int decoder_read_counter() {
  char wr_data[1] = {READ_CNTR};
  int rd_data;
  spi_transfer((uint8_t *)wr_data, (uint8_t *)&rd_data);
  printf("read counter: %d\n", rd_data);

  return rd_data;
}

/**
 * @brief Clear the decoder counter.
 */
void decoder_clear_counter() {
  char wr_data[1] = {CLR_CNTR};
  char rd_data[1];
  spi_transfer((uint8_t *)wr_data, (uint8_t *)rd_data);
}
