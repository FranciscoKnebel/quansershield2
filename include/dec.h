/**
 * @file dec.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Header for the decoder module, containing arm function helpers and
 * manipulators.
 */

#ifndef DEC_H_
#define DEC_H_

#include <galileo2io.h>
#include <stdio.h>

int counted_to_radians(int counted);
int read_decoder();

#endif
