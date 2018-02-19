#include <systemc.h>
#include <string.h>
SC_MODULE(mobile){
  sc_in<bool> clock;
  sc_in<int> x, y;
  sc_in<bool> tupleClear;
  sc_in<bool> canSend, network;
  sc_out<bool> sendRequest;
  
  void determineRoiInfo();
  
  SC_CTOR(mobile){
    SC_METHOD(determineRoiInfo);
    sensitive << clock.pos();
  }
};
