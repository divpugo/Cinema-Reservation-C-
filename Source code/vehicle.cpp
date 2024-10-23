#include "vehicle.h"
/*constructor to the vehicle class which instantiates VRN of the vehicle object.
Sets the date and time time_in of the object while setting the time_out and price to empty*/
vehicle::vehicle(std::string VRN)
{
    time_t now = time(NULL);
    struct tm *nowLocal = localtime(&now);
    std::stringstream Date, timeIn;
    Date << std::put_time(nowLocal, "%d/%m/%Y");
    timeIn << std::put_time(nowLocal, "%H:%M:%S");

    this->VRN = VRN;
    this->date = Date.str();
    this->time_in = timeIn.str();
    this->time_out = "-";
    this->price = "-";
}
/*constructor to the vehicle class which instantiates the date, VRN and time_in of the vehicle object. */
vehicle::vehicle(std::string date, std::string VRN, std::string time_in)
{
    this->VRN = VRN;
    this->date = date;
    this->time_in = time_in;
}
/*constructor to the vehicle class which instantiates the date, VRN, time_in and time_out of the vehicle object. */
vehicle::vehicle(std::string date, std::string VRN, std::string time_in, std::string time_out)
{
    this->VRN = VRN;
    this->date = date;
    this->time_in = time_in;
    this->time_out = time_out;
    this->price = chargedPrice(convertTime(time_out), convertTime(time_in));
}
/*function which gives the exit time and stores it into a variable when it is called. */
void vehicle::TimeOut()
{
    time_t now = time(NULL);
    struct tm *nowLocal = localtime(&now);
    std::stringstream timeOut;
    timeOut << std::put_time(nowLocal, "%H:%M:%S");

    this->time_out = timeOut.str();
}
/*function which converts a string to the tm type.
@param time which is in the string format */
tm *vehicle::convertTime(std::string time)
{
    struct tm *Time = new struct tm;
    std::istringstream iss(time);
    iss >> std::get_time(Time, "%H:%M:%S");
    return Time;
}
/*function which calculates the price chargeable depending on the time the car entered and exited.
@param *tOut which is a pointer to the exit time.
@param *tIn which is a pointer to the entry time.*/
std::string vehicle::chargedPrice(tm *tOut, tm *tIn)
{
    tm diff;
    if (tIn->tm_sec > tOut->tm_sec)
    {
        --tOut->tm_min;
        tOut->tm_sec += 60;
    }

    diff.tm_sec = tOut->tm_sec - tIn->tm_sec;
    if (tIn->tm_min > tOut->tm_min)
    {
        --tOut->tm_hour;
        tOut->tm_min += 60;
    }
    diff.tm_min = abs(tOut->tm_min - tIn->tm_min);
    diff.tm_hour = abs(tOut->tm_hour - tIn->tm_hour);

    if (diff.tm_hour == 0 && diff.tm_min >= 30)
        return "1.50";
    else if (diff.tm_hour == 1)
        return "3.00";
    else if (diff.tm_hour >= 2 && diff.tm_hour < 4)
        return "5.00";
    else if (diff.tm_hour >= 4 && diff.tm_hour < 8)
        return "15.00";
    else if (diff.tm_hour >= 8)
        return "30.00";
    else
        return "0.00";
}
/*function which return private variable which otherwise cannot be accessed outside of the class*/
std::string vehicle::getVRN()
{
    return VRN;
}
/*function which return private variable which otherwise cannot be accessed outside of the class*/
std::string vehicle::getPrice()
{
    return price;
}
/*function which return private variable which otherwise cannot be accessed outside of the class*/
std::string vehicle::getDate()
{
    return date;
}
/*function which return private variable which otherwise cannot be accessed outside of the class*/
std::string vehicle::getTimeIn()
{
    return time_in;
}
/*function which return private variable which otherwise cannot be accessed outside of the class*/
std::string vehicle::getTimeOut()
{
    return time_out;
}