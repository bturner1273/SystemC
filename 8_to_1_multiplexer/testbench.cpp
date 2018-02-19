// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <8to1Multiplexer.h>

int sc_main (int argc, char* argv[]) {
  //define signals
  sc_signal<bool> c0, c1, c2;
  sc_signal<int> i0, i1, i2, i3, i4, i5, i6, i7, dataOut;
  
  //connect/wire uut
  
  Multiplexer mux("8to1Multiplexer");
    mux.c0(c0);
    mux.c1(c1);
  	mux.c2(c2);
 	mux.i0(i0);
 	mux.i1(i1);
  	mux.i2(i2);
  	mux.i3(i3);
 	mux.i4(i4);
  	mux.i5(i5);
  	mux.i6(i6);
  	mux.i7(i7);
  	mux.dataOut(dataOut);
  
  //dump wave
  sc_trace_file *wf = sc_create_vcd_trace_file("8to1Multiplexer");
  sc_trace(wf, i0, "i0");
  sc_trace(wf, i1, "i1");
  sc_trace(wf, i2, "i2");
  sc_trace(wf, i3, "i3");
  sc_trace(wf, i4, "i4");
  sc_trace(wf, i5, "i5");
  sc_trace(wf, i6, "i6");
  sc_trace(wf, i7, "i7");
  sc_trace(wf, c0, "c0");
  sc_trace(wf, c1, "c1");
  sc_trace(wf, c2, "c2");
  sc_trace(wf, dataOut, "dataOut");
  
  i0.write(1);
  i1.write(2);
  i2.write(3);
  i3.write(4);
  i4.write(5);
  i5.write(6);
  i6.write(7);
  i7.write(8);
  for(int i = 0; i < 2; i++){
  c0.write(0);
  c1.write(0);
  c2.write(0);
  sc_start(1, SC_NS);
  c0.write(1);
  c1.write(0);
  c2.write(0);
  sc_start(1, SC_NS);
  c0.write(0);
  c1.write(1);
  c2.write(0);
  sc_start(1, SC_NS);
  c0.write(1);
  c1.write(1);
  c2.write(0); 
  sc_start(1, SC_NS);
  c0.write(0);
  c1.write(0);
  c2.write(1);
  sc_start(1, SC_NS);
  c0.write(1);
  c1.write(0);
  c2.write(1);
  sc_start(1, SC_NS);
  c0.write(0);
  c1.write(1);
  c2.write(1);
  sc_start(1, SC_NS);
  c0.write(1);
  c1.write(1);
  c2.write(1);
  sc_start(1, SC_NS);
  }
 
  
  sc_close_vcd_trace_file(wf);
  return 0;// Terminate simulation
  
   
}