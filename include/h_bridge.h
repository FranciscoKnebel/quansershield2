/**
 * @file h_bridge.h
 * @author Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
 * @date 26 Jun 2019
 * @brief Header for the H-bridge module, containing H-bridge function helpers
 * and manipulators.
 */

#ifndef H_BRIDGE_H_
#define H_BRIDGE_H_

#include <galileo2io.h>
#include <stdio.h>

/**
 * @brief Disable the H-bridge (left and right).
 */
int h_bridge_disable_left();
int h_bridge_disable_right();

/**
 * @brief Enable the H-bridge (left and right).
 */
int h_bridge_enable_left();
int h_bridge_enable_right();

/**
 * @brief Enable the H-bridge.
 */
int h_bridge_enable();

/**
 * @brief Disable the H-bridge.
 */
int h_bridge_disable();
#endif
