// Code your testbench here.
// Uncomment the next line for SystemC modules.
// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include "server.h"

int sc_main(int argc, char* argv[]){
  sc_clock clock("clock", 1, SC_MS);
  sc_signal<bool> crossing1,crossing2,crossing3,crossing4,go1,go2,go3,go4,stop1,stop2,stop3,stop4;
  sc_signal<double> r1speed,r2speed,r3speed,r4speed,r1distance,r2distance,r3distance,r4distance,tspeed1, tspeed2, tspeed3,tspeed4;
  sc_signal<int> currentPos1, nextPos1, currentPos2, nextPos2, currentPos3, nextPos3, currentPos4, nextPos4;
  
  //connect UUT
  Server server("Server");
  server.crossing1(crossing1);
  server.crossing2(crossing2);
  server.crossing3(crossing3);
  server.crossing4(crossing4);
  server.go1(go1);
  server.go2(go2);
  server.go3(go3);
  server.go4(go4);
  server.stop1(stop1);
  server.stop2(stop2);
  server.stop3(stop3);
  server.stop4(stop4);
  server.r1speed(r1speed);
  server.r2speed(r2speed);
  server.r3speed(r3speed);
  server.r4speed(r4speed);
  server.r1distance(r1distance);
  server.r2distance(r2distance);
  server.r3distance(r3distance);
  server.r4distance(r4distance);
  server.tspeed1(tspeed1);
  server.tspeed2(tspeed2);
  server.tspeed3(tspeed3);
  server.tspeed4(tspeed4);
  server.currentPos1(currentPos1);
  server.nextPos1(nextPos1);
  server.currentPos2(currentPos2);
  server.nextPos2(nextPos2);
  server.currentPos3(currentPos3);
  server.nextPos3(nextPos3);
  server.currentPos4(currentPos4);
  server.nextPos4(nextPos4);
  server.clock(clock);
  
  
  //dump to wave file
  sc_trace_file *wf = sc_create_vcd_trace_file("Server");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, crossing1, "crossing1");
  sc_trace(wf, crossing2, "crossing2");
  sc_trace(wf, crossing3, "crossing3");
  sc_trace(wf, crossing4, "crossing4");
  sc_trace(wf, r1speed, "r1speed");
  sc_trace(wf, r1distance, "r1distance");
  sc_trace(wf, r2speed, "r2speed");
  sc_trace(wf, r2distance, "r2distance");
  sc_trace(wf, r3speed, "r3speed");
  sc_trace(wf, r3distance, "r3distance");
  sc_trace(wf, r4speed, "r4speed");
  sc_trace(wf, r4distance, "r4distance");
  sc_trace(wf, go1, "go1");
  sc_trace(wf, stop1, "stop1");
  sc_trace(wf, go2, "go2");
  sc_trace(wf, stop2, "stop2");
  sc_trace(wf, go3, "go3");
  sc_trace(wf, stop3, "stop3");
  sc_trace(wf, go4, "go4");
  sc_trace(wf, stop4, "stop4");
  sc_trace(wf, tspeed1, "tspeed1");
  sc_trace(wf, tspeed2, "tspeed2");
  sc_trace(wf, tspeed3, "tspeed3");
  sc_trace(wf, tspeed4, "tspeed4");
  sc_trace(wf, currentPos1, "currentPos1");
  sc_trace(wf, nextPos1, "nextPos1");
  sc_trace(wf, currentPos2, "currentPos2");
  sc_trace(wf, nextPos2, "nextPos2");
  sc_trace(wf, currentPos3, "currentPos3");
  sc_trace(wf, nextPos3, "nextPos3");
  sc_trace(wf, currentPos4, "currentPos4");
  sc_trace(wf, nextPos4, "nextPos4");
  
 //test shows all cases finishing 
  stop1.write(0);
  stop2.write(0);
  stop3.write(0);
  stop4.write(0);
  for(int i = 0; i < 17; i++){
 sc_start(10,SC_MS);
 crossing1.write(1);
 crossing2.write(1);
 crossing3.write(1);
 crossing4.write(1);
 sc_start(1,SC_MS);
 crossing1.write(0);
 crossing2.write(0);
 crossing3.write(0);
 crossing4.write(0);
  }
  
  
//this tests every Robot sending crossing once
/*sc_start(10, SC_MS);
crossing1.write(1);
sc_start(1, SC_MS);
crossing1.write(0);
sc_start(10,SC_MS);
crossing2.write(1);
sc_start(1, SC_MS);
crossing2.write(0);
sc_start(10,SC_MS);
crossing3.write(1);
sc_start(1, SC_MS);
crossing3.write(0);
sc_start(10,SC_MS);
crossing4.write(1);
sc_start(1, SC_MS);
crossing4.write(0);
sc_start(10,SC_MS);
*/
  
  sc_close_vcd_trace_file(wf);
  return 0;
}