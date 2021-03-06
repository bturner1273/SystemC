// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <3FullMobileScanners.h>
#include <server.h>

int sc_main(int argc, char* argv[]){
   //declare signals
   sc_clock clock("clock", 4, SC_MS); //sample 							rate = 250 per second
   sc_signal<bool> canSend1, canSend2, canSend3, network, sendRequest1, sendRequest2, sendRequest3, tupleClear;
  
/*
sc_signal<bool> m1_request, m2_request, m3_request;
//sc_signal<bool> m1_sending;
sc_signal<bool> network;
sc_signal<bool> m1_CanSend, m2_CanSend, m3_CanSend;*/
  
  //connect uut
  ThreeMobileAndSensors mob("ThreeMobilesAndSensors");
  mob.clock(clock);
  mob.tupleClear(tupleClear);
  mob.canSend1(canSend1);
  mob.canSend2(canSend2);
  mob.canSend3(canSend3);
  mob.network(network);
  mob.sendRequest1(sendRequest1);
  mob.sendRequest2(sendRequest2);
  mob.sendRequest3(sendRequest3);
  
  server server("Server");
  server.clock(clock);
  server.network(network);
  server.m1_request(sendRequest1);
  server.m2_request(sendRequest2);
  server.m3_request(sendRequest3);
  server.m1_CanSend(canSend1);
  server.m2_CanSend(canSend2);
  server.m3_CanSend(canSend3);
  
  //dump to wave file
  sc_trace_file *wf = sc_create_vcd_trace_file("ThreeMobilesAndSensors");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, canSend1, "canSend1");
  sc_trace(wf, canSend2, "canSend2");
  sc_trace(wf, canSend3, "canSend3");
  sc_trace(wf, network, "network");
  sc_trace(wf, tupleClear, "tupleClear");
  sc_trace(wf, sendRequest1, "sendRequest1");
  sc_trace(wf, sendRequest2, "sendRequest2");
  sc_trace(wf, sendRequest3, "sendRequest3");
  
  
  network.write(0);
  //canSend1.write(1);
  //canSend2.write(1);
  //canSend3.write(1);
  sc_start(5000, SC_MS);
  tupleClear.write(1);
  sc_start(5000, SC_MS);
  sc_close_vcd_trace_file(wf);
  return 0;
  
}
