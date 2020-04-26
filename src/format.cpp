#include <string>

#include "format.h"

using std::string;
using std::to_string;

string Format::ElapsedTime(long seconds) {
    long int hours = seconds / 3600;
    long int minutes = (seconds%3600)/60;
    long int remainder = (seconds%3600)%60;
    return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(remainder);
}