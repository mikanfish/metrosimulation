/*
 *  Train.cpp
 *  Gabby Fischberg
 *  2/10/23
 *
 *  CS 15 Project 1 - Metrosim
 *
 *  Train definitions for project 1, metrosim. 
 * 
 * Implementation of a train class that creates a simulation of a metro
 * given a text file of stations. Can be given a file of commands to 
 * control the simulation or have user input commands.
 *
 */

#include "Train.h"
#include <algorithm>

using namespace std;

/*
 * name:      Train default constructor
 * purpose:   initialize an empty Train
 * arguments: none
 * returns:   none
 * effects:   stopp to 0, nummstations to -1, passengers to 0
 */
Train::Train(){
    stopp = 0;
    nummstations = -1; 
    passengercount = 0; 
}
/*
 * name:      Train destructor
 * purpose:   delete [] train array
 * arguments: none
 * returns:   none
 * effects:   frees memory
 */
Train::~Train(){
   delete [] trainarr; 
}
/*
 * name:      openordie
 * purpose:   open a file or die trying
 * arguments: streamtype template &input, string filename
 * returns:   none
 * effects:   opens a file or exits
 */
template<typename streamtype>
void Train::openordie(streamtype &input, string filename){
    input.open(filename);
    if (not input.is_open()){
        cerr << "Error: could not open file stat.txt" + filename << endl;
        exit(EXIT_FAILURE);
    }
}
/*
 * name:      countstations
 * purpose:   count number of stations in given file
 * arguments: filename
 * returns:   int number of stations
 * effects:   updates nummstation
 */
int Train::countstations(string filename){
    ifstream instream; 
    openordie(instream, filename);
    string currline; 
    int count = 0; 
    while(getline(instream, currline)) {
        count++;
    }
    instream.close();
    return count; 
}
/*
 * name:      getnumstations
 * purpose:   gets private variable nummstations
 * arguments: none
 * returns:   nummstations
 * effects:   none
 */
int Train::getnumstations(){
    return nummstations; 
}
/*
 * name:      setinfilegiven
 * purpose:   sets command file
 * arguments: none
 * returns:   none
 * effects:   infilegiven updated
 */
void Train::setinfilegiven (string filename){
    infilegiven = filename; 
}
/*
 * name:      setoutputfile
 * purpose:   sets output file
 * arguments: none
 * returns:   none
 * effects:   outputfile updated
 */
void Train::setoutputfile (string filename) {
    outputfile = filename; 
}
/*
 * name:      initializetrain
 * purpose:   make and initialize array of passengerqueues for train
 * arguments: numstations
 * returns:   none
 * effects:   creates an array of passengerqueues of size [nummstations]
 */
void Train::initializetrain(int numstations){
    trainarr = new PassengerQueue[numstations];
}
/*
 * name:      initializestations
 * purpose:   initializes list of stations 
 * arguments: none
 * returns:   none
 * effects:   initializes stationlist with station numbers
 */
void Train::initializestations(){
    ifstream instream; 
    openordie(instream, infilegiven);
    int count = countstations(infilegiven); 
    nummstations = count; 
    for (int i = 0; i < nummstations; i++){
        Station currstation; 
        currstation.stationnumber = i; 
        stationlist.push_back(currstation);
    }
    instream.close();
}

/*
 * name:      initializetest
 * purpose:   tests if correctly initialized station numbers 
            this is because typename streamtype must be priv
            so test is in train function 
 * arguments: none
 * returns:   none
 * effects:   tests if initilization went correctly
 */
void Train::initalizetest(){
    std::list<Station>::iterator it; 
    for (it = stationlist.begin(); it != stationlist.end(); it++) {
        std::cout << it->stationnumber;
    }
}
/*
 * name:      addpassenger
 * purpose:   adds a passnger to passengerqueue at station
 * arguments: from, to
 * returns:   none
 * effects:   adds passenger 
 */
void Train::addpasssenger(int from, int to){
    passengercount++; 
    Passenger currpass(passengercount, from, to);
    std::list<Station>::iterator it; 
    for (it = stationlist.begin(); it != stationlist.end(); it++) {
        if (from == it->stationnumber){
            it->station.enqueue(currpass);
        }
    }
}
/*
 * name:      runloop
 * purpose:   runs main loop of fielding commands from input
 * arguments: istream &input, ostream &output
 * returns:   none
 * effects:   none
 */
void Train::runloop(istream &input, ostream &output){
    printtrain();
    char command, secondcomm; 
    bool shouldcont = true;  
    while (shouldcont == true){
        cout << "Command? "; 
        input >> command;
        if (command == 'm') {
            input >> secondcomm; 
            if (secondcomm == 'm') {
                metromove(output);
            } else { shouldcont = false; }
        } else if (command == 'p') {
            int fromm, too; 
            input >> fromm >> too; 
            addpasssenger(fromm, too);
        } if (shouldcont == true) {
            printtrain();
        }
    }
    std::cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}
/*
 * name:      metromove
 * purpose:   moves train to next stop, passes ostream to next function
 * arguments: ostream &output
 * returns:   none
 * effects:   stopp updated
 */
void Train::metromove(ostream &output){
    onTrain();
    if (stopp == nummstations - 1) {
        stopp = 0; 
    }
    else {
        stopp++;
    }
    offTrain(output);
}

/*
 * name:      printtrain
 * purpose:   prints train interface with train at current stop
 * arguments: none
 * returns:   none
 * effects:   prints train
 */
void Train::printtrain(){
    ifstream instream; 
    openordie(instream, infilegiven);
    string currline; 
    int count = 0; 
    printpassengers();
    while(getline(instream, currline)) {
        if (stopp == count) {
            cout << "TRAIN: ["  << count << "] ";
        } else {
        cout << "       [" << count << "] ";
        } cout << currline << " {";
        std::list<Station>::iterator it; 
        for (it = stationlist.begin(); it != stationlist.end(); it++) {
            if (count == it->stationnumber){
            it->station.print(cout);
            }
        }
        cout << "}" << endl;
        count++; 
    }
    instream.close();
}
/*
 * name:      printpassengers
 * purpose:   prints passengers currently on train
 * arguments: none
 * returns:   none
 * effects:   prints passengers
 */
void Train::printpassengers(){
    cout << "Passengers on the train: {";
    for (int i = 0; i < nummstations; i++) {
        trainarr[i].print(cout);
    }
    cout << "}" << endl;
}
/*
 * name:      printpassengers
 * purpose:   prints passengers currently on train
 * arguments: none
 * returns:   none
 * effects:   prints passengers
 */
void Train::onTrain() {
    std::list<Station>::iterator it; 
    for (it = stationlist.begin(); it != stationlist.end(); it++) {
        if (stopp == it->stationnumber){
            if (it->station.size() != 0) {
                int temp = it->station.size(); 
                for (int i = 0; i < temp; i++) {
                     //adds to index[passenger's destination]
                trainarr[it->station.front().to].enqueue(it->station.front());
                    it->station.dequeue();
                }
            }
        }
    }
}
/*
 * name:      offTrain
 * purpose:   removes passengers off train
 * arguments: ostream &output
 * returns:   none
 * effects:   updates trainarr
 */
void Train::offTrain(ostream &output){
if (trainarr[stopp].size() != 0) {
        int temp = trainarr[stopp].size(); 
        for (int i = 0; i < temp; i++) {
            Passenger currpassenger = trainarr[stopp].front();
            printoutput(currpassenger.id, output);
            if (currpassenger.to == stopp) {
                trainarr[stopp].dequeue();
            }
        }
    }
}
/*
 * name:      printoutput
 * purpose:   prints passengers leaving train to output file
 * arguments: ostream &output
 * returns:   none
 * effects:   prints output
 */
void Train::printoutput(int num, ostream &output){
    ifstream instream; 
    openordie(instream, infilegiven);
    string currline; 
    output << "Passenger " << num << " left train at station ";
    std::list<Station>::iterator it; 
    for (int i = 0; i <= stopp; i++) {
        getline(instream, currline);
    }
    output << currline << endl;
    instream.close();
}

