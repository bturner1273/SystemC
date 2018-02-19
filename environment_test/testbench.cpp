#include <systemc.h>
#include "Environment.h"


int sc_main(int argc, char* argv[]){
  
  
  sc_clock clock("clock", 1, SC_MS);
  sc_signal<int> nextPos1, nextPos2, nextPos3, nextPos4;
  sc_signal<bool> stop1,stop2,stop3,stop4;
  sc_signal<int> person1, person2, person3;
  
  Environment ppl("Environment");
  ppl.nextPos1(nextPos1);
  ppl.nextPos2(nextPos2);
  ppl.nextPos3(nextPos3);
  ppl.nextPos4(nextPos4);
  ppl.stop1(stop1);
  ppl.stop2(stop2);
  ppl.stop3(stop3);
  ppl.stop4(stop4);
  ppl.person1(person1);
  ppl.person2(person2);
  ppl.person3(person3);
  ppl.clock(clock);

  
  
  sc_trace_file *wf = sc_create_vcd_trace_file("Environment");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, nextPos1, "nextPos1");
  sc_trace(wf, nextPos2, "nextPos2");
  sc_trace(wf, nextPos3, "nextPos3");
  sc_trace(wf, nextPos4, "nextPos4");
  sc_trace(wf, stop1, "stop1");
  sc_trace(wf, stop2, "stop2");
  sc_trace(wf, stop3, "stop3");
  sc_trace(wf, stop4, "stop4");
  sc_trace(wf, person1, "person1");
  sc_trace(wf, person2, "person2");
  sc_trace(wf, person3, "person3");
  
  nextPos1.write(3);
  nextPos2.write(24);
  nextPos3.write(5);
  nextPos4.write(16);
  

  sc_start(20000,SC_MS);
  
  sc_close_vcd_trace_file(wf);
  return 0;
}
  