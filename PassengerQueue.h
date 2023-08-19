/*
 *  PassengerQueue.h
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  PassengerQueue interface for project 1, metrosim.
 *  Includes queue functions - front, enqueue, dequeue,
 *  size, and print. 
 *
 */

#ifndef PASSENGER_QUEUE
#define PASSENGER_QUEUE

#include "Passenger.h"
#include <string>
#include <iostream>
#include <list>

class PassengerQueue {
    public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

    private:

    std::list<Passenger> plist;     
};

#endif