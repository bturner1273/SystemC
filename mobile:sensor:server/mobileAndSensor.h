#include <systemc.h>
#include <mobile.h>
#include <sensor.h>

SC_MODULE(mobileAndSensor){
  sc_in<bool> clock;
  sc_out<bool> ROI1,ROI2,ROI3,ROI4,ROI5,ROI234,ROI24,ROI34;
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
    mob->ROI1(ROI1);
    mob->ROI2(ROI2);
    mob->ROI3(ROI3);
    mob->ROI4(ROI4);
    mob->ROI5(ROI5);
    mob->ROI24(ROI24);
    mob->ROI34(ROI34);
    mob->ROI234(ROI234);
    mob->canSend(canSend);
    mob->network(network);
    mob->sendRequest(sendRequest);
    
  }
   
};