#include "processor.h"
#include "linux_parser.h"
#include <vector>

using std::stof;
using std::vector;
using std::string;


float Processor::Utilization() {
    vector<string> ticks = LinuxParser::CpuUtilization();
    float usage;
    if(ticks.size()==10){
        float nonIdleTime = stof(ticks[0]) + stof(ticks[1]) + stof(ticks[2]) + stof(ticks[5]) + stof(ticks[6]) + stof(ticks[7]);
        this->idleTime = stof(ticks[3]) + stof(ticks[4]);
        this->totalTime = nonIdleTime + this->idleTime;

        if(this->prevTotalTime == 0){
            usage = (this->totalTime - this->idleTime)/this->totalTime;
        }

        else {
            float totald = this->totalTime - this->prevTotalTime;
            float idled = this->idleTime - this->prevIdleTime;
            usage = (totald - idled)/totald;
        }

        this->prevIdleTime = this->idleTime;
        this->prevTotalTime = this->totalTime;

        return usage;
    }
}