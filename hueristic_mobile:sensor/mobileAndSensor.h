#include <systemc.h>
#include <mobile.h>
#include <sensor.h>

SC_MODULE(mobileAndSensor){
  sc_in<bool> clock;
  sc_in<bool> canSend, network;
  sc_out<bool> sendRequest;
  sc_signal<int> x, y;
  
  
  sensor* sense;
  mobile* mob;
  
  SC_CTOR(mobileAndSensor){
    sense = new sensor("sensor");
    sense->x(x);
    sense->y(y);
    sense->clock(clock);
    
    mob = new mobile("mobile");
    mob->clock(clock);
    mob->x(x);
    mob->y(y);
    mob->canSend(canSend);
    mob->network(network);
    mob->sendRequest(sendRequest);
    
  }
   
};