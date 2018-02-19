#include <systemc.h>

SC_MODULE(Multiplexer){
  sc_in<bool> c0, c1, c2;
  sc_in<int> i0, i1, i2, i3, i4, i5, i6, i7;
  sc_out<int> dataOut;
  
  void mux_process();
  
  SC_CTOR(Multiplexer){
    SC_METHOD(mux_process);
   	sensitive << c0 << c1 << c2;
  }
  
};