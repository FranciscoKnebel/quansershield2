/**
 * @file dec.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Header for the decoder module, containing arm function helpers and
 * manipulators.
 */

#ifndef DECODER_H_
#define DECODER_H_

#include <galileo2io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_decoder();
int counted_to_radians(int counted);

#endif
