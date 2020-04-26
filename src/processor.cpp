#include "processor.h"
#include "linux_parser.h"
#include <vector>

using std::stof;
using std::vector;
using std::string;


float Processor::Utilization() {
    vector<string> jiffies = LinuxParser::CpuUtilization();
    if (jiffies.size() == 10){
        prevActive = curActive;
        prevTotal = curTotal;
        curActive = stof(jiffies[0]) + stof(jiffies[1]) + stof(jiffies[2]) + stof(jiffies[5]) + stof(jiffies[6]) + stof(jiffies[7]);
        curTotal = curActive + stof(jiffies[3]) + stof(jiffies[4]) + stof(jiffies[8]) + stof(jiffies[9]);
    }
    return(curActive - prevActive)/(curTotal -prevTotal);
}
