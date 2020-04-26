#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  

 private:
 float idleTime;
 float totalTime;
 float prevIdleTime;
 float prevTotalTime{0};
};

#endif