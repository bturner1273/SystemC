// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include "pulseCounter.h"

int sc_main(int argc, char* argv[]){
 sc_signal<bool> reset, _start, _stop, overflow;
 sc_signal<int> counter;
 sc_clock clock("clock", 100, SC_NS);
  pulseCounter c1("Pulse Counter");
  c1.reset(reset);
  c1._start(_start);
  c1._stop(_stop);
  c1.overflow(overflow);
  c1.counter(counter);
  c1.clock(clock);
  
  
  sc_trace_file *wf = sc_create_vcd_trace_file("Pulse Counter");
  sc_trace(wf, reset, "reset");
  sc_trace(wf, _start, "start");
  sc_trace(wf, _stop, "stop");
  sc_trace(wf, overflow, "overflow");
  sc_trace(wf, counter, "counter");
  sc_trace(wf, clock, "clock");
  
  _start.write(0);
  _stop.write(1);
  reset.write(1);
  sc_start(100,SC_NS);
  _start.write(1);
  _stop.write(0);
  reset.write(0);
  sc_start(100, SC_NS);
  _start.write(0);
  sc_start(400, SC_NS);
  _start.write(1);
  sc_start(100,SC_NS);
  _start.write(0);
  sc_start(2000, SC_NS);
  reset.write(1);
  sc_start(100, SC_NS);
  reset.write(0);
  sc_start(100,SC_NS);
   _start.write(1);
  sc_start(100, SC_NS);
  _start.write(0);
  sc_start(400, SC_NS);
  _start.write(1);
  sc_start(100,SC_NS);
  _start.write(0);
  _stop.write(1);
  sc_start(100,SC_NS);
  
  
  sc_close_vcd_trace_file(wf);
  return 0;
  
  
  
}
