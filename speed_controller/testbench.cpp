// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include "speedController.h"

int sc_main(int argc, char* argv[]){
  sc_signal<bool> accel, brake, reset;
  sc_signal<int> speed;
  sc_clock clock("clock", 100, SC_NS);
  
  speedController sc("speedController");
  sc.accel(accel);
  sc.brake(brake);
  sc.reset(reset);
  sc.clock(clock);
  sc.speed(speed);
  
  
  sc_trace_file *wf = sc_create_vcd_trace_file("speedController");
  sc_trace(wf, accel, "accel");
  sc_trace(wf, reset, "reset");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, speed, "speed");
  sc_trace(wf, brake, "brake");
  
  sc_start(1,SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(900, SC_NS);
  accel.write(0);
  sc_start(100,SC_NS);
  accel.write(1);
  sc_start(900,SC_NS);
  brake.write(0);
  sc_start(700, SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(600, SC_NS);
  accel.write(0);
  brake.write(1);
  sc_start(700, SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(500, SC_NS);
  accel.write(1);
  brake.write(1);
  sc_start(300, SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(700, SC_NS);
  accel.write(0);
  brake.write(0);
  sc_start(600, SC_NS);
  reset.write(1);
  sc_start(100, SC_NS);
  reset.write(0);
  accel.write(1);
  brake.write(0);
  sc_start(1000, SC_NS);
  accel.write(0);
  brake.write(0);
  sc_start(200, SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(500, SC_NS);
  accel.write(0);
  brake.write(0);
  sc_start(600, SC_NS);
  accel.write(1);
  brake.write(0);
  sc_start(100, SC_NS);
  
  sc_close_vcd_trace_file(wf);
  return 0;
}
  
  
