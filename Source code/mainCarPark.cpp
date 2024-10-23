#include "vehicle.h"
#include "hashTable.h"
#include "List.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <string>
#include <ctime>
#include <iomanip>
#include <list>

/*delcarations of functions */
void openFile();
void displayFileContent();
int checkUserInput();
void addVehicle();
void exitVehicle();
void listHistory();
void listReport();
void saveToFile(std::string date, std::string VRN, std::string time_in, std::string time_out, std::string price);

/*declaration of global variables*/
int userInput;
bool flag = true;
std::string filename;

/*constructing the hash table and linked lsit*/
hash Parking;
List history;

/*function which opens file based on the filename user input.
reads line from the file and stored data in variables before adding said data in either the car park hash table
or hisory list.
function notifies user if filename entered is invalid.*/
void openFile()
{
    std::cout << "\t**********************************************************************" << std::endl;
    std::cout << "\tNOTE:THE FILE YOU INSERT MUST BE IN THE SAME DIRECTORY AS PROGRAM FILE" << std::endl;
    std::cout << "\t**********************************************************************" << std::endl;
    std::cout << "\t\tEnter the file name: ";
    std::getline(std::cin, filename);

    std::fstream myFile;
    myFile.open(filename, std::ios::in);
    if (myFile.is_open())
    {
        std::string line;
        while (std::getline(myFile, line))
        {
            if (line[0] == 'D' || line.length() < 2)
                continue;

            std::stringstream ss(line);
            std::string date, VRN, time_in, time_out;

            std::getline(ss, date, ',');
            std::getline(ss, VRN, ',');
            std::getline(ss, time_in, ',');
            std::getline(ss, time_out, ',');

            if (time_out == "-")
            {
                Parking.addVehicle(date, VRN, time_in);
            }
            else
            {
                vehicle obj(date, VRN, time_in, time_out);
                std::string price;
                price = obj.getPrice();
                history.addNode(date, VRN, time_in, time_out, price);
                saveToFile(date, VRN, time_in, time_out, price);
            }
        }
    }
    else
    {
        std::cout << "\t\tINVALID FILENAME ENTERED" << std::endl;
    }
}

/*
Function performing user input validation.
Verifying that user input is an integer.
Prints out error message if user input is incorrect.
@userInput which is of type integer returned
*/
int checkUserInput()
{
    bool inptFail;
    do
    {
        std::cout << "\tChoice: ";
        std::cin >> userInput;
        inptFail = std::cin.fail();
        if (std::cin.fail())
        {
            std::cout << "\tInvalid input. Try again." << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (inptFail == true);

    return userInput;
}
/*function which prompts user to enter vehicle registration number to add vehicle to the hashtable.
makes use of the vehicle class to construct vehicle object to obtain data such as date and entry time*/
void addVehicle()
{
    std::string VRN;
    std::string date;
    std::string time_in;
    std::cout << "\tEnter the Vehicle Registration Number (VRN): ";
    std::getline(std::cin, VRN);

    vehicle obj1(VRN);
    date = obj1.getDate();
    time_in = obj1.getTimeIn();

    Parking.addVehicle(date, VRN, time_in);
}
/*function which prompts user to enter vehicle registration number to remove vehicle to the hashtable
and add it to the history linked list..
makes use of the vehicle class to construct vehicle object to obtain data such as exit time and price payable*/
void exitVehicle()
{
    std::string VRN;
    std::string date;
    std::string time_in;
    std::string time_out;
    std::string price;
    std::cout << "\tEnter the Vehicle Registration Number (VRN): ";
    std::getline(std::cin, VRN);
    date = Parking.getDate(VRN);
    time_in = Parking.getTimeIn(VRN);

    vehicle obj(date, VRN, time_in);
    obj.TimeOut();
    time_out = obj.getTimeOut();

    vehicle obj1(date, VRN, time_in, time_out);
    price = obj1.getPrice();

    std::cout << "\n\tThe price payable is: £" << price << std::endl;
    Parking.removeVehicle(VRN);
    history.addNode(date, VRN, time_in, time_out, price);

    saveToFile(date, VRN, time_in, time_out, price);
}
/*function which displays a report for a specific date. It displays the date, entry and exit time as well
as the price payable of vehicles that have exited the car park.*/
void listHistory()
{

    std::string date;
    std::cout << "\tEnter the date (dd/mm/yyyy) for which to display the parking history: ";
    std::getline(std::cin, date);
    history.searchDate(date);
}
/*function which displays a if a vehicle with the registration number inout by the user is currently parked in the lot.
 It displays the date and entry time of the vehicle with the specific VRN. Confirms that vehicle has not exited car park.*/
void listReport()
{
    std::string VRN;
    std::cout << "\tEnter the Vehicle Registration Number (VRN) to check if vehicle is currently parked: ";
    std::getline(std::cin, VRN);
    Parking.findVehicle(VRN);
}

/*function which opens file or creates one called history if does not already exist.
Stores a history of vehicles that have left the car park. Stores the date, entry and exit time, VRN as well as the price payable.*/
void saveToFile(std::string date, std::string VRN, std::string time_in, std::string time_out, std::string price)
{
    std::fstream myFile;
    myFile.open("history.txt", std::ios::app);

    myFile << date << "," << VRN << "," << time_in << "," << time_out << "," << price << "\n";
    myFile.close();
}

/*
Function which outputs onto command line.
Provides user with information to navigate
through program.
*/
void menu()
{
    std::cout << "\n\t**********************************************************************" << std::endl;
    std::cout << "\t**********************************************************************" << std::endl;
    std::cout << "\n\t\tWELCOME TO THE CAR PARK SYSTEM" << std::endl;
    std::cout << "\n\t\tChoose 1 to enter a new vehicle." << std::endl;
    std::cout << "\t\tChoose 2 to exit a vehicle." << std::endl;
    std::cout << "\t\tChoose 3 to view history for a specific date." << std::endl;
    std::cout << "\t\tChoose 4 to view report of a vehicle." << std::endl;
    std::cout << "\n\n\t\tChoose 5 to EXIT program." << std::endl;
    std::cout << "\t**********************************************************************" << std::endl;
    std::cout << "\t**********************************************************************" << std::endl;
}

/*
Main menu which is called when program
is executed.

Calls out the menu function which displays
onto command line.

Calls out checkUserInput() function which
performs user input validation.

Calls out functions for different options
picked by user.
*/
int main()
{
    openFile();
    int inpt;
    while (flag)
    {
        menu();
        inpt = checkUserInput();
        switch (inpt)
        {
        case 1:
            addVehicle();

            break;
        case 2:
            exitVehicle();
            break;
        case 3:
            listHistory();
            break;
        case 4:
            listReport();
            break;

        case 5:
            exit(1);
        default:
        {
            std::cout << "\tInvalid input. Try again." << std::endl;

            break;
        }
        }
    }

    return 0;
}