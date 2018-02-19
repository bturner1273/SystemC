// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <FourBitRippleCarryAdder.h>


int sc_main (int argc, char* argv[]) {

  sc_signal<bool> a0,a1,a2,a3,b0,b1,b2,b3,cin,s0,s1,s2,s3,carryOut;

FourBitFullAdder fourbitfa("fourbitfulladder");
  fourbitfa.a0(a0);
  fourbitfa.a1(a1);
  fourbitfa.a2(a2);
  fourbitfa.a3(a3);
  fourbitfa.b0(b0);
  fourbitfa.b1(b1);
  fourbitfa.b2(b2);
  fourbitfa.b3(b3);
  fourbitfa.cin(cin);
  fourbitfa.s0(s0);
  fourbitfa.s1(s1);
  fourbitfa.s2(s2);
  fourbitfa.s3(s3);
  fourbitfa.carryOut(carryOut);
  
  sc_trace_file *wf = sc_create_vcd_trace_file("FourBitFa");
  sc_trace(wf, a0, "a0");
  sc_trace(wf, a1, "a1");
  sc_trace(wf, a2, "a2");
  sc_trace(wf, a3, "a3");
  sc_trace(wf, b0, "b0");
  sc_trace(wf, b1, "b1");
  sc_trace(wf, b2, "b2");
  sc_trace(wf, b3, "b3");
  sc_trace(wf, cin, "cin");
  sc_trace(wf, s0, "s0");
  sc_trace(wf, s1, "s1");
  sc_trace(wf, s2, "s2");
  sc_trace(wf, s3, "s3");
  sc_trace(wf, carryOut, "carryOut");
  
  
  for(int i = 0; i < 2; i++){
    sc_start(1, SC_NS);
    cin = 0;
    a0 = 0;
    a1 = 0;
    a2 = 1;
    a3 = 0;
    b0 = 0;
    b1 = 0;
    b2 = 1;
    b3 = 0;
    sc_start(1, SC_NS);
    a0 = 1;
    a1 = 0;
    a2 = 1;
    a3 = 0;
    b0 = 1;
    b1 = 0;
    b2 = 1;
    b3 = 0;
    sc_start(1, SC_NS);
  }

  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
  
}
