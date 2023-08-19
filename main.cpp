/*
 *  main.cpp
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 * main function for project 1, metrosim
 * handles opening files, running main loop, giving errors
 * if files cannot be opened and handling commands
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Train.h"

using namespace std;

int main(int argc, char *argv[]) {       
        //enforce correct usage
        if (argc < 3 ) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
        cerr << endl;
        exit(EXIT_FAILURE); } 

        Train train;
        train.setinfilegiven(argv[1]);
        train.setoutputfile(argv[2]);
        train.initializestations();
        train.initializetrain(train.getnumstations());

        ofstream outstream;
        outstream.open(argv[2]);
        if (argc == 3) {
                train.runloop(cin, outstream); 
        } else if (argc == 4) {
                ifstream instream;
                instream.open(argv[3]);
                if (not instream.is_open()){
                        cerr << "Error: could not open file " << argv[3];
                        cerr << endl;
                        exit(EXIT_FAILURE);
                }
                train.runloop(instream, outstream); 
                instream.close();
        }
        outstream.close();
        return 0;
}