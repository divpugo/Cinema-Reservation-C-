#ifndef _HASH_H
#define _HASH_H

#include <iostream>
#include <string>

/*
  Base class for hash table function
  @attribute private VRN, date, time_in which cannot be accessed outside of the class
  @method hash() which constructs class
  @method Hash which hashes and creates an index for the items in the table
  @param key which is input by the user
  @method addVehicle which inserts a vehicle to the hash table
  @params date, VRN, time_in which is essential to the abstract data type of vehicle
  @method findVehicle which looks up a vehicle item from the hash table
  @method removeVehicle which removes a vehicle item from the hash table
  @method getDate which returns the date of a vehicle item from hash table
  @method getTimeIn which return the entry time of a vehicle item from a hash table
  @para for @methods findVehicle, removeVehicle, getDate, getTimeIn is VRN which is input by the user
  and used to match up for a specific vehicle
*/
class hash
{
private:
    static const int tableSize = 50;

    struct vehicle
    {
        std::string VRN;
        std::string date;
        std::string time_in;
        vehicle *next;
    };

    vehicle *HashTable[tableSize];

public:
    hash();
    int Hash(std::string key);
    void addVehicle(std::string date, std::string VRN, std::string time_in);
    void findVehicle(std::string VRN);
    void removeVehicle(std::string VRN);
    std::string getDate(std::string VRN);
    std::string getTimeIn(std::string VRN);
};

#endif