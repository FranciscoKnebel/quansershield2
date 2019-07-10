/**
 * @file signal_module.h
 * @author Francisco Knebel, Luciano Zancan Mazzutti, Rodrigo Dal Ri
 * @date 06 Jul 2019
 * @brief Module containing signal handling functions.
 */

#ifndef QUANSER_SIGNAL_H
#define QUANSER_SIGNAL_H

    #include <signal.h> 
    #include <stdio.h>
    #include <stdlib.h>

    void handle_termination(int (*callback)());

#endif

