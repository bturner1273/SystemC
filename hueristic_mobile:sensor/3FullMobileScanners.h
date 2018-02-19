#include<systemc.h>
#include<mobileAndSensor.h>

SC_MODULE(ThreeMobileAndSensors){
 sc_in<bool> clock;
 sc_in<bool> canSend1, canSend2, canSend3, network;
 sc_out<bool> sendRequest1, sendRequest2, sendRequest3;
  
 mobileAndSensor *mAnds1, *mAnds2, *mAnds3;

  SC_CTOR(ThreeMobileAndSensors){
    mAnds1 = new mobileAndSensor("mAnds1");
    mAnds1->clock(clock);
    mAnds1->canSend(canSend1);
    mAnds1->network(network);
    mAnds1->sendRequest(sendRequest1);
    
    mAnds2 = new mobileAndSensor("mAnds2");
    mAnds2->clock(clock);
    mAnds2->canSend(canSend2);
    mAnds2->network(network);
    mAnds2->sendRequest(sendRequest2);
    
    mAnds3 = new mobileAndSensor("mAnds3");
    mAnds3->clock(clock);
    mAnds3->canSend(canSend3);
    mAnds3->network(network);
    mAnds3->sendRequest(sendRequest3);
  }
};