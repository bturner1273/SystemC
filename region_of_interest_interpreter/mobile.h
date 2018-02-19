#include <systemc.h>

SC_MODULE(mobile){
  sc_in<bool> clock;
  sc_in<int> x, y;
  sc_out<bool> ROI1,ROI2,ROI3,ROI4,ROI5;
  sc_out<double> t1,t2,t3,t4,t5;
  
  void determineRoiInfo();
  
  SC_CTOR(mobile){
    SC_METHOD(determineRoiInfo);
    sensitive << clock.pos();
  } 
};