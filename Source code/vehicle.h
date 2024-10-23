#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>

/*
  Base class for vehicle function
  @attribute private VRN, date, time_in, time_out and price which cannot be accessed outside of the class
  @method vehicle(std::string VRN) which constructs class object with only VRN as input
  @param VRN which is input by the user
  @method vehicle(std::string date, std::string VRN, std::string time_in) which constructs class object
  @param date, VRN and time_in which is input by the user which will reset those vraibles based on the input
  @method vehicle(std::string date, std::string VRN, std::string time_in, std::string time_out) which constructs class object
  @param date, VRN, time_in and time_out which is input by the user which will reset those vraibles based on the input
  @method TimeOut() which sets the exit time of the vehicle wehn called upon
  @method chargedPrice() which calculates the price to be payed when the vehicle leaves
  @param tm *t1, tm *t2 which are pointer variables to the entry and exit times
  @method tm *convertTime() which converts string times to tm structure
  @param time which is taken to be converted
  @method getVRN which return private variable VRN
  @method getPrice which return private variable VRN
  @method getDate which return private variable VRN
  @method getTimeIn which return private variable VRN
  @method getTimeOut which return private variable VRN
*/

class vehicle
{
private:
  std::string date;
  std::string VRN;
  std::string time_in;
  std::string time_out;
  std::string price;

public:
  vehicle(std::string VRN);
  vehicle(std::string date, std::string VRN, std::string time_in);
  vehicle(std::string date, std::string VRN, std::string time_in, std::string time_out);
  void TimeOut();
  std::string chargedPrice(tm *t1, tm *t2);
  tm *convertTime(std::string time);
  std::string getVRN();
  std::string getPrice();
  std::string getDate();
  std::string getTimeIn();
  std::string getTimeOut();
};

#endif