// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <FullAdder.h>
int sc_main (int argc, char* argv[]) {
  
  sc_signal<bool> sig_a, sig_b, sig_cin, sig_sum, sig_carry;
  
  
  //connect uut
  FullAdder adder("adder");
  adder.a(sig_a);
  adder.b(sig_b);
  adder.cin(sig_cin);
  adder.sum(sig_sum);
  adder.carry_out(sig_carry);
  
  
  //open wave file (.vcd)
  sc_trace_file *wf = sc_create_vcd_trace_file("HalfAdder");
  sc_trace(wf, sig_a, "sig_a");
  sc_trace(wf, sig_b, "sig_b");
  sc_trace(wf, sig_cin, "sig_cin");
  sc_trace(wf, sig_sum, "sig_sum");
  sc_trace(wf, sig_carry, "sig_carry");
  
  for(int i = 0; i < 2; i++){
  sig_a = 0;
  sig_b = 0;
  sig_cin = 0;
  sc_start(1, SC_NS);
  sig_a = 0;
  sig_b = 0;
  sig_cin = 1;
  sc_start(1, SC_NS);
  sig_a = 0;
  sig_b = 1;
  sig_cin = 0;
  sc_start(1, SC_NS);
  sig_a = 0;
  sig_b = 1;
  sig_cin = 1;
  sc_start(1, SC_NS);
  sig_a = 1;
  sig_b = 0;
  sig_cin = 0;
  sc_start(1, SC_NS);
  sig_a = 1;
  sig_b = 0;
  sig_cin = 1;
  sc_start(1, SC_NS);
  sig_a = 1;
  sig_b = 1;
  sig_cin = 0;
  sc_start(1, SC_NS);  
  sig_a = 1;
  sig_b = 1;
  sig_cin = 1;
  sc_start(1, SC_NS);
  }
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
  
  
}