#include "Command.h"

Command::Command(const string& name):name(name)
{

}

string Command::getToday() const
{
    time_t now = time(nullptr);      
    tm localTime = {};
    localtime_s(&localTime, &now);    

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d"); 
    return oss.str();
}