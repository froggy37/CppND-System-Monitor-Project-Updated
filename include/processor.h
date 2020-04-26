#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  

 private:
 float prevActive;
 float prevTotal;
 float curTotal;
 float curActive;
};

#endif