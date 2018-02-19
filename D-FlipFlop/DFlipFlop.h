#include <systemc.h>
SC_MODULE(DFlipFlop){
  sc_in<bool> clock, d;
  sc_out<bool> q;
  
  void getQ(){
    q = d; 
  }
  
  SC_CTOR(DFlipFlop){
    SC_METHOD(getQ);
    sensitive << clock.pos();
    
  }
  
  
};