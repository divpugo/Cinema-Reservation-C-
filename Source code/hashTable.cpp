#include "hashTable.h"

#include <iostream>
#include <list>
#include <cstring>

/*constructor from the hashtable class
sets the variable to empty when the hastable is initally contructed*/
hash::hash()
{
    for (int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new vehicle;
        HashTable[i]->date = "empty";
        HashTable[i]->VRN = "empty";
        HashTable[i]->time_in = "empty";
        HashTable[i]->next = NULL;
    }
}
/*function to add a new vehicle item into the hashTable
@param date which is generated from the vehicle class and is input
@param VRN which is input by the user when adding a new vehicle
@param time_in which is generated when vehicle is added from the vehicle class function
@attribute index which stores the address whereby the vehicle will be stored in the table*/
void hash::addVehicle(std::string date, std::string VRN, std::string time_in)
{
    int index = Hash(VRN);

    if (HashTable[index]->VRN == "empty")
    {
        HashTable[index]->VRN = VRN;
        HashTable[index]->date = date;
        HashTable[index]->time_in = time_in;
    }
    else
    {
        vehicle *Ptr = HashTable[index];
        vehicle *n = new vehicle;
        n->VRN = VRN;
        n->date = date;
        n->time_in = time_in;
        n->next = NULL;
        while (Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
    std::cout << "\tVehicle having registration number " << VRN << " added to parking lot." << std::endl;
}

/*function to find a vehicle from the hashTable based on the vehicle registration number
@param VRN which is input by the user to search for the vehicle
@attribute index which stores the address whereby the vehicle is stored in the table
@attribute foundVRN which is a boolean variable which determines if the vehicle in the table matches user input*/
void hash::findVehicle(std::string VRN)
{
    int index = Hash(VRN);

    bool foundVRN = false;
    std::string date;
    std::string time_in;

    vehicle *Ptr = HashTable[index];

    while (Ptr != NULL)
    {
        if (Ptr->VRN == VRN)
        {
            foundVRN = true;
            date = Ptr->date;
            time_in = Ptr->time_in;
        }
        Ptr = Ptr->next;
    }
    if (foundVRN == true)
    {
        std::cout << "\tVehicle having registration number " << VRN << " parked on the " << date << " at " << time_in << std::endl;
    }
    else
    {
        std::cout << "\tNo vehicle with this registration number currently parked here." << std::endl;
    }
}

/*function to acess the date of specific vehicle from the hashTable based on the vehicle registration number
@param VRN which is input by the user to search for the vehicle
@attribute index which stores the address whereby the vehicle is stored in the table*/
std::string hash::getDate(std::string VRN)
{
    int index = Hash(VRN);

    std::string date = "";

    vehicle *Ptr = HashTable[index];

    while (Ptr != NULL)
    {
        if (Ptr->VRN == VRN)
        {
            date = Ptr->date;
        }
        Ptr = Ptr->next;
    }

    return date;
}

/*function to acess the entry time of specific vehicle from the hashTable based on the vehicle registration number
@param VRN which is input by the user to search for the vehicle
@attribute index which stores the address whereby the vehicle is stored in the table*/
std::string hash::getTimeIn(std::string VRN)
{
    int index = Hash(VRN);

    std::string time_in = "";

    vehicle *Ptr = HashTable[index];

    while (Ptr != NULL)
    {
        if (Ptr->VRN == VRN)
        {
            time_in = Ptr->time_in;
        }
        Ptr = Ptr->next;
    }

    return time_in;
}

/*function which hashes and creates the index
@param VRN which is input by the user to search for the vehicle to be hashed and to create the index
@attribute index which stores the address whereby the vehicle is stored in the table*/
int hash::Hash(std::string key)
{
    int hash = 0;
    int index;

    for (unsigned i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }

    index = hash % tableSize;

    return index;
}

/*function to remove a vehicle from the hashTable based on the vehicle registration number
@param VRN which is input by the user to search for the vehicle
@attribute index which stores the address whereby the vehicle is stored in the table
function traverses through each vehicle item to determine whether the VRN entered by the user matches the VRN inside the hash table*/
void hash::removeVehicle(std::string VRN)
{
    int index = Hash(VRN);

    vehicle *delPtr;
    vehicle *P1;
    vehicle *P2;

    if (HashTable[index]->VRN == "empty" && HashTable[index]->date == "empty")
    {
        std::cout << "\tVehicle having registration number " << VRN << " was not found in the parking lot." << std::endl;
    }
    else if (HashTable[index]->VRN == VRN && HashTable[index]->next == NULL)
    {
        HashTable[index]->VRN = "empty";
        HashTable[index]->date = "empty";
        HashTable[index]->time_in = "empty";

        std::cout << "\tVehicle having registration number " << VRN << " has successfully exited the parking lot." << std::endl;
    }
    else if (HashTable[index]->VRN == VRN)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        std::cout << "\tVehicle having registration number " << VRN << " has successfully exited the parking lot." << std::endl;
    }
    else
    {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while (P1 != NULL && P1->VRN != VRN)
        {
            P2 = P1;
            P1 = P1->next;
        }
        if (P1 == NULL)
        {
            std::cout << "\tVehicle having registration number " << VRN << " was not found in the parking lot." << std::endl;
        }
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            std::cout << "\tVehicle having registration number " << VRN << " has successfully exited the parking lot." << std::endl;
        }
    }
}