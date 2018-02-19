// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <and.h>
int sc_main(int argc, char* argv[]){
  //declare signals
  sc_signal<bool> a, b, aANDb;
  
  //connect UUT
  AND andGate("ANDGate");
  andGate.a(a);
  andGate.b(b);
  andGate.aANDb(aANDb);
  
  //dump to a waveform
  sc_trace_file *wf = sc_create_vcd_trace_file("ANDGate");
  sc_trace(wf, a, "a");
  sc_trace(wf, b, "b");
  sc_trace(wf, aANDb, "aANDb");
  
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