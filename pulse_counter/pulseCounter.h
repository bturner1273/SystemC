#include <systemc.h>

SC_MODULE(pulseCounter){
 sc_in<bool> clock, reset, _start, _stop;
 sc_out<bool> overflow;
 sc_out<int> counter;
 bool canStart;
  
  void start();
  void stop();
  void count();
  
  SC_CTOR(pulseCounter){
    SC_METHOD(start);
    sensitive << _start.pos();
    SC_METHOD(stop);
    sensitive << _stop.neg();
    SC_METHOD(count);
    sensitive << clock.pos() << clock.neg();
    
  }
  
  
};