/**
 * @file spi.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Module containing SPI helper functions.
 */

#ifndef SPI_H_
#define SPI_H_

#include <fcntl.h>
#include <getopt.h>
#include <linux/spi/spidev.h>
#include <linux/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

void send_error(const char *s);
int spi_init();
int spi_close();
void spi_transfer(uint8_t *tx, uint8_t *rx);
void spi_stat();

#endif
