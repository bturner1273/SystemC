// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include "DFlipFlop.h"

int sc_main (int argc, char* argv[]) {
 //initialize signals
  sc_signal<bool> clock, d, q;
  //connect UUT (unit under test)
  DFlipFlop dflipflop("D Flip-Flop");
  dflipflop.clock(clock);
  dflipflop.d(d);
  dflipflop.q(q);
  
  //start simulation before initializing  	and dumping to wave file
  sc_start(1, SC_NS);
  //initialize wave file
  sc_trace_file *wf = sc_create_vcd_trace_file("D Flip-Flop");
  //dump signals to file
  sc_trace(wf, clock, "clock");
  sc_trace(wf, d, "d");
  sc_trace(wf, q, "q");
  
  //initialize variables
  for(int i = 0; i < 2; i++){
  clock = 0;
  d = 0;
  sc_start(1,SC_NS);
  clock = 1;
  sc_start(1,SC_NS);
  clock = 0;
  d = 1;
  sc_start(1,SC_NS);
  clock = 1;
  sc_start(1,SC_NS);
  clock = 0;
  d = 0;
  sc_start(1,SC_NS);
  clock = 1;
  sc_start(2,SC_NS);
  }
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation

}
  
  
  
  
  
  
