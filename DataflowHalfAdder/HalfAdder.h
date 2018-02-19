#include <systemc.h>
SC_MODULE(HalfAdder){
 sc_in<bool> a, b;
 sc_out<bool> sum, carry_out;
 
  void function();
  
  SC_CTOR(HalfAdder){
    SC_METHOD(function);
    sensitive << a << b;
  }
  
  
};