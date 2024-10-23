CXX = g++
CXXFLAGS = -g -Wall -Wextra

program: mainCarPark.cpp vehicle.o hashTable.o List.o
		$(CXX) $(CXXFLAGS) -o program mainCarPark.cpp vehicle.o hashTable.o List.o
vehicle.o: vehicle.cpp vehicle.h
		$(CXX) $(CXXFLAGS) -c vehicle.cpp
hashTable.o: hashTable.cpp hashTable.h
		$(CXX) $(CXXFLAGS) -c hashTable.cpp
List.o: List.cpp List.h
		$(CXX) $(CXXFLAGS) -c List.cpp

.PHONY: clean
clean:
		rm *.o program