/*
 *  PassengerQueue.cpp
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  PassengerQueue definitions for project 1, metrosim
 * 
 * Implementation of a passengerqueue class that uses std::list
 * to implment the queue.
 *
 */

#include "PassengerQueue.h"

using namespace std; 

/*
 * name:      front
 * purpose:   returns front Passenger stored in PQ without dequeueing
 * arguments: none
 * returns:   first passenger in PassengerQueue
 * effects:   none
 */
Passenger PassengerQueue::front(){
    return plist.front();
}
/*
 * name:      dequeue
 * purpose:   removes passenger at front of PQ
 * arguments: none
 * returns:   none
 * effects:   first passenger removed
 */
void PassengerQueue::dequeue(){
    plist.pop_front();
}
/*
 * name:      enqueue
 * purpose:   adds passenger to end of queue
 * arguments: none
 * returns:   none
 * effects:   one passenger to back of queue
 */
void PassengerQueue::enqueue(const Passenger &passenger){
    plist.push_back(passenger);
}
/*
 * name:      size
 * purpose:   returns size of passengerqueue
 * arguments: none
 * returns:   size of passengerqueue
 * effects:   none
 */
int PassengerQueue::size(){
    return plist.size();
}
/*
 * name:      print
 * purpose:   prints passengerqueue in specified format
 * arguments: none
 * returns:   none
 * effects:   prints passengerqueue
 */
void PassengerQueue::print(std::ostream &output){
    std::list<Passenger>::iterator it; 

    for (it = plist.begin(); it != plist.end(); it++) {
        it->print(output); 
    }
    
}