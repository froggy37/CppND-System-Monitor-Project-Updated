#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor& System::Cpu() {
    this->cpu_ = Processor();
    return this->cpu_;
}

vector<Process>& System::Processes() {
    vector<int> pids = LinuxParser::Pids();
    vector<Process> currentProcs;
    for (auto pid : pids){
        Process newProcess = Process(pid, this->UpTime_);
        currentProcs.push_back(newProcess);
    }
    std::sort(currentProcs.begin(), currentProcs.end());
    this->processes_ = currentProcs;
    return this->processes_;
}

std::string System::Kernel() const { return LinuxParser::Kernel(); }

float System::MemoryUtilization() const { return LinuxParser::MemoryUtilization();}

std::string System::OperatingSystem() const { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() const { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() const { return LinuxParser::TotalProcesses(); }

long System::UpTime() { 
    this->UpTime_ = LinuxParser::UpTime();
    return LinuxParser::UpTime();
}