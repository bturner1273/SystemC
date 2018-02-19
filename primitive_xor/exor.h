#include <systemc.h>

SC_MODULE(EXOR){
  sc_in<bool> a, b;
  sc_out<bool> aEXORb;
  
  void exor_process();
  
  SC_CTOR(EXOR){
    SC_METHOD(exor_process);
    sensitive << a << b;
  }
  
};