#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

int Process::Pid() { return this->pid_;}

float Process::CpuUtilization() const{
    
    float cpuUsage = 0.0;
    vector<string> stat = LinuxParser::CpuUtilization(this->pid_);
    if(stat.size() == 52){
        float totalTime = stof(stat[13]) + stof(stat[14]) + stof(stat[15]) + stof(stat[16]);
        float procUpTime = this->sysUpTime_ - (LinuxParser::UpTime(this->pid_));
        cpuUsage = (totalTime/sysconf(_SC_CLK_TCK))/procUpTime;
    }
    return cpuUsage;
}

string Process::Command() { return LinuxParser::Command(this->pid_);}

string Process::Ram() { return LinuxParser::Ram(this->pid_);}

string Process::User() {
    string uid_ = LinuxParser::Uid(this->pid_);
    if (uid_.empty()){
        return "notFound";
    }
    return LinuxParser::User(stoi(uid_));
}

long Process::UpTime() {
    float procUpTime = this->sysUpTime_ - (LinuxParser::UpTime(this->pid_));
    return procUpTime;
}

bool Process::operator<(Process const& a) const{
    return (this->CpuUtilization() > a.CpuUtilization());
}