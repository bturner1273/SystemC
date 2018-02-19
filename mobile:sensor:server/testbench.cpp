// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <mobileAndSensor.h>


int sc_main(int argc, char* argv[]){
 
  //declare signals
   sc_clock clock("clock", 4, SC_MS); //sample 							rate = 250 per second
   
  sc_signal<bool> ROI1,ROI2,ROI3,ROI4,ROI5,ROI234,ROI24,ROI34,canSend,network,sendRequest;
  
  mobileAndSensor mob("mobile");
  mob.clock(clock);
  mob.ROI1(ROI1);
  mob.ROI2(ROI2);
  mob.ROI3(ROI3);
  mob.ROI4(ROI4);
  mob.ROI5(ROI5);
  mob.ROI24(ROI24);
  mob.ROI34(ROI34);
  mob.ROI234(ROI234);
  mob.canSend(canSend);
  mob.network(network);
  mob.sendRequest(sendRequest);
  
  sc_trace_file *wf = sc_create_vcd_trace_file("mobileAndSensor");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, ROI1, "roi1");
  sc_trace(wf, ROI2, "roi2");
  sc_trace(wf, ROI3, "roi3");
  sc_trace(wf, ROI4, "roi4");
  sc_trace(wf, ROI5, "roi5");
  sc_trace(wf, ROI24, "roi24");
  sc_trace(wf, ROI34, "roi34");
  sc_trace(wf, ROI234, "roi234");
  sc_trace(wf, canSend, "canSend");
  sc_trace(wf, network, "network");
  sc_trace(wf, sendRequest, "sendRequest");

  
  network.write(0);
  canSend.write(1);
  
  sc_start(10000, SC_MS);
  sc_close_vcd_trace_file(wf);
  return 0;
  
}
  /*
 //declare signals
   sc_clock clock("clock", 4, SC_MS); //sample 							rate = 250 per second
 
  sc_signal<int> x, y;
  sc_signal<double> t1,t2,t3,t4,t5;
  sc_signal<bool> ROI1, ROI2, ROI3, ROI4, ROI5, ROI24, ROI34, ROI234;
  sc_signal<bool> canSend, network, sendRequest;
 // sc_fifo_out_if<int> packet;
  
  
  //connect uuts
  
   //mobile mob("mobile", "TimesAtEachPosition.txt"); for parameterized filename
  
  mobile mob("mobile");
  mob.clock(clock);
//  mob.packet(packet);
  mob.x(x);
  mob.y(y);
  mob.canSend(canSend);
  mob.network(network);
  mob.sendRequest(sendRequest);
  mob.ROI1(ROI1);
  mob.ROI2(ROI2);
  mob.ROI3(ROI3);
  mob.ROI4(ROI4);
  mob.ROI5(ROI5);
  mob.ROI24(ROI24);
  mob.ROI34(ROI34);
  mob.ROI234(ROI234);
  
  
   sensor sense("sensor");
  sense.x(x);
  sense.y(y);
  sense.clock(clock);
  
  //dump to wave file
  sc_trace_file *wf = sc_create_vcd_trace_file("mobileAndSensor");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, x, "x");
  sc_trace(wf, y, "y");
  sc_trace(wf, ROI1, "roi1");
  sc_trace(wf, ROI2, "roi2");
  sc_trace(wf, ROI3, "roi3");
  sc_trace(wf, ROI4, "roi4");
  sc_trace(wf, ROI5, "roi5");
  sc_trace(wf, ROI24, "roi24");
  sc_trace(wf, ROI34, "roi34");
  sc_trace(wf, ROI234, "roi234");
 // sc_trace(wf, packet, "packet");
  sc_trace(wf, canSend, "canSend");
  sc_trace(wf, network, "network");
  sc_trace(wf, sendRequest, "sendRequest");

  
  //start sim
  network.write(0);
  canSend.write(1);
  sc_start(100000, SC_MS);
  sc_close_vcd_trace_file(wf);
  return 0;

}*/