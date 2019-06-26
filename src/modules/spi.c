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
 * @file modules/spi.c
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Module containing SPI helpers and functions.
 */

#include <spi.h>

/**
 * @brief Calculates the size of an array.
 */
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

/**
 * @brief Helper function for errors, to warn users about failures in program
 * execution.
 */
void send_error(const char *s) {
  perror(s);
  abort();
}

const char *device = "/dev/spidev1.0";
uint32_t mode;
uint8_t bits = 8;
uint32_t speed = 1000;
uint16_t delay;

int fd;

/**
 * @brief Initializes the SPI.
 */
int spi_init() {
  int ret = 0;
  fd = open(device, O_RDWR);
  if (fd < 0)
    send_error("Erro ao abrir o dispositivo");

  mode = SPI_MODE_0;

  ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1)
    send_error("Erro ao setar o modo do SPI");

  ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
  if (ret == -1)
    send_error("Erro ao setar o modo do SPI");

  ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  if (ret == -1)
    send_error("Erro ao setar os bits por palavra");

  ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
  if (ret == -1)
    send_error("Erro ao ler os bits por palavra");

  ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
  if (ret == -1)
    send_error("Erro ao setar a velocidade maxima em HZ");

  ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
  if (ret == -1)
    send_error("Erro ao ler a velocidade maxima em HZ");

  return ret;
}

/**
 * @brief Closes the SPI file descriptor.
 */
int spi_close() { return close(fd); }

/**
 * @brief Transfer messages from tx to rx.
 */
void spi_transfer(uint8_t *tx, uint8_t *rx) {
  int ret;

  struct spi_ioc_transfer tr = {
      .tx_buf = (unsigned long)tx,
      .rx_buf = (unsigned long)rx,
      .len = ARRAY_SIZE(tx),
      .delay_usecs = delay,
      .speed_hz = speed,
      .bits_per_word = bits,
  };
  puts('enviando...');
  ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
  if (ret < 1) {
    send_error("Erro ao tentar enviar mensagem pelo SPI.");
  }

  printf("ret %d - array size %d\n", ret, ARRAY_SIZE(rx));
  for (ret = 0; ret < ARRAY_SIZE(rx); ret++) {
    printf("%x ", rx[ret]);
  }
}

/**
 * @brief Get SPI data values.
 */
void spi_stat() {
  printf("Modo SPI: 0x%x\n", mode);
  printf("bits por palavra: %d\n", bits);
  printf("Maxima velocidade: %d Hz (%d KHz)\n", speed, speed / 1000);
}
