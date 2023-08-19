/*
 *  Passenger.cpp
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  Passenger definitions for project 1, metrosim
 * 
 *  implmementation of print function for individual passenger:
 *  prints passenger member variables
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/*
 * name:      print
 * purpose:   prints passenger with specified format
 * arguments: none
 * returns:   none
 * effects:   none
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
