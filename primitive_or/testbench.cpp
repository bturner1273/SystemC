// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <or.h>

int sc_main(int argc, char* argv[]){
  //declare signals
  sc_signal<bool> a, b, aORb;
  
  //connect UUT
  OR orGate("ORGate");
  orGate.a(a);
  orGate.b(b);
  orGate.aORb(aORb);
  
  //dump to a waveform
  sc_trace_file *wf = sc_create_vcd_trace_file("ORGate");
  sc_trace(wf, a, "a");
  sc_trace(wf, b, "b");
  sc_trace(wf, aORb, "aORb");
  
  //start sim
  for(int i = 0; i < 2; i++){
  a.write(0);
  b.write(0);
  sc_start(10, SC_NS);
  a.write(1);
  b.write(0);
  sc_start(10, SC_NS);
  a.write(0);
  b.write(1);
  sc_start(10, SC_NS);
  a.write(1);
  b.write(1);
  sc_start(10, SC_NS);
  }
  
  
  sc_close_vcd_trace_file(wf);
  return 0;

}