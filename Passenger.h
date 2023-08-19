/*
 *  Passenger.h
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  Passenger interface for project 1, metrosim. 
 *  provided to me and unedited
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
