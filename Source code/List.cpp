#include "List.h"

#include <iostream>
#include <cstdlib>

/*constructor from the list class
sets the variable to empty when the list is initally contructed*/
List::List()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

/*function which compares date variable in a node in order to be sorted
@param newNodeDate which is the date of the new node being created and added
@param currNodeDate which is the date of the current node accessed*/
bool List::sameDates(std::string newNodeDate, std::string currNodeDate)
{
    if (newNodeDate.compare(currNodeDate) == 0)
    {
        return true;
    }
    return false;
}

/*function to add a new vehicle item into the list
@param date which is input when the vehicle is being added to history
@param VRN which is input by the user when adding a new vehicle
@param time_in which is generated when vehicle is first added from the vehicle class function
@param time_out which is generated when the vehicle is called to exit the car park
@method sameDates which is used to compare dates in order for the list to be sorted*/
void List::addNode(std::string date, std::string VRN, std::string time_in, std::string time_out, std::string price)
{
    nodePtr n = new node;
    n->next = NULL;
    n->date = date;
    n->VRN = VRN;
    n->time_in = time_in;
    n->time_out = time_out;
    n->price = price;

    if (head != NULL)
    {
        curr = head;

        bool flag = sameDates(n->date, curr->date);

        while (curr->next != NULL && flag == false)
        {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

/*function to remove vehicle item into the list
@param delData which will store the pointer and memory address of the node that needs to be deleted and removed from the list*/
void List::deleteNode(std::string delData)
{

    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->VRN != delData)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        std::cout << delData << " was not in the list" << std::endl;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        delete delPtr;
        std::cout << " The vehicle having registration number " << delData << "was deleted from history." << std::endl;
    }
}

/*function which looks up a vehicle from the list.
@param date which is input by the user and which
will be used to match agaisnt the data stored in the node
dor the vehicle to be accessed and displayed.
function traverses through each node of the list to verfiy that the condition is met.*/
void List::searchDate(std::string date)
{
    curr = head;
    std::cout << "\n\tThe following vehicles were parked on the " << date << std::endl;
    std::cout << "\n\tVRN, Time In, Time Out, Charged Price\n"
              << std::endl;
    while (curr != NULL)
    {

        if (curr->date != date)
        {

            curr = curr->next;
        }
        else if (curr->date == date)
        {
            std::cout << "\t" << curr->VRN << " " << curr->time_in << " " << curr->time_out << " " << curr->price << std::endl;
            curr = curr->next;
        }
        else
        {
            break;
        }
    }
}
