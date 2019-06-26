/**
 * @file h_bridge.h
 * @author Francisco Knebel, Luciano Zancan, Rodrigo Dal Ri
 * @date 11 Dez 2018
 * @brief Header for the H-bridge module, containing H-bridge function helpers
 * and manipulators.
 */

#ifndef H_BRIDGE_H_
#define H_BRIDGE_H_

#include <galileo2io.h>
#include <stdio.h>

/**
 * @brief Disable the H-bridge, on GPIO38.
 */
int h_bridge_disable();

/**
 * @brief Enable the H-bridge, on GPIO38.
 */
int h_bridge_enable();

#endif
