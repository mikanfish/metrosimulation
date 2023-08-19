#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 


MetroSim: main.o PassengerQueue.o Passenger.o Train.o
	$(CXX) $(CXXFLAGS) -o MetroSim $^
	

# rules for .o files
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(CXXFLAGS) -c Passenger.cpp

Train.o: Train.cpp Train.h 
	$(CXX) $(CXXFLAGS) -c Train.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

unit_test: unit_test_driver.o PassengerQueue.o Passenger.o Train.o
	$(CXX) $(CXXFLAGS) $^

provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
					Train.h Train.cpp \
					main.cpp \
				    unit_tests.h Makefile README

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
