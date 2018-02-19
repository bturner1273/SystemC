// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <sensor.h>

int sc_main (int argc, char* argv[]) {
  //declare signals
  sc_clock clock("clock", 4, SC_MS); //sample 							rate = 250 per second
 
  sc_signal<int> x, y;
  
  //map uut
  sensor sense("sensor");
  sense.x(x);
  sense.y(y);
  sense.clock(clock);
  
  //dump to wave file
  sc_trace_file *wf = 		sc_create_vcd_trace_file("Sensor");
  sc_trace(wf, x, "x");
  sc_trace(wf, y, "y");
  sc_trace(wf, clock, "clock");
  
  sc_start(100, SC_MS);
  sc_close_vcd_trace_file(wf);
  return 0;
  
  
  
}