// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <mobile.h>
#include <sensor.h>


int sc_main(int argc, char* argv[]){
 //declare signals
   sc_clock clock("clock", 4, SC_MS); //sample 							rate = 250 per second
 
  sc_signal<int> x, y;
  sc_signal<double> t1,t2,t3,t4,t5;
  sc_signal<bool> ROI1, ROI2, ROI3, ROI4, ROI5;
  
  
  //connect uuts
  
   //mobile mob("mobile", "TimesAtEachPosition.txt"); for parameterized filename
  
  mobile mob("mobile");
  mob.clock(clock);
  mob.x(x);
  mob.y(y);
  mob.ROI1(ROI1);
  mob.ROI2(ROI2);
  mob.ROI3(ROI3);
  mob.ROI4(ROI4);
  mob.ROI5(ROI5);
  mob.t1(t1);
  mob.t2(t2);
  mob.t3(t3);
  mob.t4(t4);
  mob.t5(t5);
  
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
  sc_trace(wf, t1, "t1");
  sc_trace(wf, t2, "t2");
  sc_trace(wf, t3, "t3");
  sc_trace(wf, t4, "t4");
  sc_trace(wf, t5, "t5");
  
  //start sim
  sc_start(10000, SC_MS);
  sc_close_vcd_trace_file(wf);
  return 0;

}