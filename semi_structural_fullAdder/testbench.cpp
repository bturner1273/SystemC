// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <FullAdder.h>
int sc_main (int argc, char* argv[]) {
  sc_signal<bool> a, b, cin, sum, carry_out;
  //connect uut
FullAdder fa("FA");
  fa.a(a);
  fa.b(b);
  fa.cin(cin);
  fa.sum(sum);
  fa.carry_out(carry_out);
  
  sc_start(1, SC_NS);
  //open wave file (.vcd)
  sc_trace_file *wf = sc_create_vcd_trace_file("FullAdder");
  sc_trace(wf, a, "a");
  sc_trace(wf, b, "b");
  sc_trace(wf, sum, "sum");
  sc_trace(wf, cin, "cin");
  sc_trace(wf, carry_out, "carry_out");
  
  for(int i = 0; i < 2; i++){
  a.write(0);
  b = 0;
  cin = 0;
  sc_start(1, SC_NS);
  a = 0;
  b = 0;
  cin = 1;
  sc_start(1, SC_NS);
  a = 0;
  b = 1;
  cin = 0;
  sc_start(1, SC_NS);
  a = 0;
  b = 1;
  cin = 1;
  sc_start(1, SC_NS);
  a = 1;
  b = 0;
  cin = 0;
  sc_start(1, SC_NS);
  a = 1;
  b = 0;
  cin = 1;
  sc_start(1, SC_NS);
  a = 1;
  b = 1;
  cin = 0;
  sc_start(1, SC_NS);
  a = 1;
  b = 1;
  cin = 1;
  sc_start(1, SC_NS);   
  }
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
  
  
}