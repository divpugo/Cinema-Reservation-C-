#ifndef _LIST_H
#define _LISTH_H

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>

/*
  Base class for linkedlist function
  @attribute private VRN, date, time_in, time_out and price which cannot be accessed outside of the class and 
  wich forms part of the data stored in a node
  @attribute nodePtr head, nodePtr curr, nodePtr temp which are pointer variables to different nodes
  @method sameDates() which will compare the dates for the nodes to be sorted in the single linked list
  @method List() which constructs class
  @params newNodeDate and currNodeDate which will be compared to be sorted
  @method addNode which inserts a vehicle to the hash table
  @params date, VRN, time_in, time_out and price which is essential to the abstract data type of node
  @method searchDate which looks up a date item from nodes in the linked list
  @param date which is input by the user
  @method deleteNode which removes a node from the linked list
  @param delData which is the pointer vriable of the node to be removed from the linked list
*/

class List
{
private:
    typedef struct node
    {
        std::string date;
        std::string VRN;
        std::string time_in;
        std::string time_out;
        std::string price;

        node *next;
    } * nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

    bool sameDates(std::string newNodeDate, std::string currNodeDate);

public:
    List();
    void addNode(std::string date, std::string VRN, std::string time_in, std::string time_out, std::string price);
    void deleteNode(std::string delData);
    void searchDate(std::string date);
};

#endif