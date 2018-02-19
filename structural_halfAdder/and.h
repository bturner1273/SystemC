#include <systemc.h>

SC_MODULE(AND){
  sc_in<bool> a, b;
  sc_out<bool> aANDb;
  
  void and_process();
  
  SC_CTOR(AND){
    SC_METHOD(and_process);
    sensitive << a << b;
  }
  
};