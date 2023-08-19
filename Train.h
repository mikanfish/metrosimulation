/*
 *  Train.h
 *  Gabby Fischberg
 *  2/15/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  Train interface for project 1, metrosim. Includes relevant functions 
 *  such as moving train, and deal with passengers going on/off
    the train. 
 * 
 *
 */

#ifndef TRAIN
#define TRAIN

#include "PassengerQueue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

class Train{
    public: 
    const std::string MOVE = "m m";
    const std::string PASS = "p ";
    const std::string FIN = "m f";

    Train();
    ~Train();
    void addpasssenger(int from, int to);
    void runloop(std::istream &input, std::ostream &output);
    void metromove(std::ostream &output);

    void setoutputfile (std::string filename);
    void setinfilegiven(std::string filename);
    int getnumstations();
    //just a test
    void initalizetest();

    void initializetrain(int numstations); 
    void initializestations();

    private: 
    struct Station {
        PassengerQueue station;
        int stationnumber; 
    };
    int stopp; 
    int passengercount;
    int nummstations; 
    std::string infilegiven;
    std::string outputfile; 

    PassengerQueue *trainarr; 
    void readfile(std::string filename);
    int countstations(std::string filename);
   
    void printoutput(int num, std::ostream &output);
    void printtrain();
    void printpassengers();
    void onTrain();
    void offTrain(std::ostream &output);

    std::list<Station> stationlist;
    template<typename streamtype>
    void openordie(streamtype &input, std::string filename);

}; 

#endif