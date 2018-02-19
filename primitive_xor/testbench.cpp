// Code your testbench here.
// Uncomment the next line for SystemC modules.#include <systemc.h>
#include <systemc.h>
#include <exor.h>
int sc_main(int argc, char* argv[]){
  //declare signals
  sc_signal<bool> a, b, aEXORb;
  
  //connect UUT
  EXOR exorGate("EXORGate");
  exorGate.a(a);
  exorGate.b(b);
  exorGate.aEXORb(aEXORb);
  
  //dump to a waveform
  sc_trace_file *wf = sc_create_vcd_trace_file("EXORGate");
  sc_trace(wf, a, "a");
  sc_trace(wf, b, "b");
  sc_trace(wf, aEXORb, "aEXORb");
  
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