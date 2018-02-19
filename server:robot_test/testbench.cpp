// Code your testbench here.
// Uncomment the next line for SystemC modules.

#include <systemc>
#include <robot.h>
#include <robot2.h>
#include <robot3.h>
#include <robot4.h>
#include <server.h>

//remember to label in waveform that robot speed is in meters/milliSecond

int sc_main (int argc, char* argv[]) {
    

  sc_clock clock("clock", 1, SC_MS);
  sc_signal<bool> crossing1,crossing2,crossing3,crossing4,go1,go2,go3,go4,stop1,stop2,stop3,stop4;
  sc_signal<double> r1speed,r2speed,r3speed,r4speed,r1distance,r2distance,r3distance,r4distance,tspeed1, tspeed2, tspeed3,tspeed4,r1distanceCrossed,r2distanceCrossed,r3distanceCrossed,r4distanceCrossed;
  sc_signal<int> currentPos1, nextPos1, currentPos2, nextPos2, currentPos3, nextPos3, currentPos4, nextPos4;
  
  
  //Connect UUTs
  Server server("Server");
  server.crossing1(crossing1); //
  server.crossing2(crossing2);
  server.crossing3(crossing3);
  server.crossing4(crossing4);
  server.go1(go1);//
  server.go2(go2);
  server.go3(go3);
  server.go4(go4);
  server.stop1(stop1);//
  server.stop2(stop2);
  server.stop3(stop3);
  server.stop4(stop4);
  server.r1speed(r1speed);//
  server.r2speed(r2speed);
  server.r3speed(r3speed);
  server.r4speed(r4speed);
  server.r1distance(r1distance);//
  server.r2distance(r2distance);
  server.r3distance(r3distance);
  server.r4distance(r4distance);
  server.tspeed1(tspeed1);//
  server.tspeed2(tspeed2);
  server.tspeed3(tspeed3);
  server.tspeed4(tspeed4);
  server.currentPos1(currentPos1);//
  server.nextPos1(nextPos1);//
  server.currentPos2(currentPos2);
  server.nextPos2(nextPos2);
  server.currentPos3(currentPos3);
  server.nextPos3(nextPos3);
  server.currentPos4(currentPos4);
  server.nextPos4(nextPos4);
  server.clock(clock);//
  server.r1distanceToCross(r1distanceCrossed);//
  server.r2distanceToCross(r2distanceCrossed);
  server.r3distanceToCross(r3distanceCrossed);
  server.r4distanceToCross(r4distanceCrossed);
  
  
  Robot robot1("robot1");
  robot1.go(go1);//
  robot1.stop(stop1);//
  robot1.clock(clock);//
  robot1.speed(r1speed);//
  robot1.distance(r1distance);//
  robot1.targetSpeed(tspeed1);//
  robot1.crossing(crossing1);//
 robot1.distanceCrossed(r1distanceCrossed);//
  
  Robot2 robot2("robot2");
    robot2.go_r2(go2);//
  robot2.stop_r2(stop2);//
  robot2.clock(clock);//
  robot2.speed_r2(r2speed);//
  robot2.distance_r2(r2distance);//
  robot2.targetSpeed_r2(tspeed2);//
  robot2.crossing_r2(crossing2);//
 robot2.distanceCrossed_r2(r2distanceCrossed);//
   
  Robot3 robot3("robot3");
    robot3.go_r3(go3);//
  robot3.stop_r3(stop3);//
  robot3.clock(clock);//
  robot3.speed_r3(r3speed);//
  robot3.distance_r3(r3distance);//
  robot3.targetSpeed_r3(tspeed3);//
  robot3.crossing_r3(crossing3);//
 robot3.distanceCrossed_r3(r3distanceCrossed);//
  
   Robot4 robot4("robot4");
    robot4.go_r4(go4);//
  robot4.stop_r4(stop4);//
  robot4.clock(clock);//
  robot4.speed_r4(r4speed);//
  robot4.distance_r4(r4distance);//
  robot4.targetSpeed_r4(tspeed4);//
  robot4.crossing_r4(crossing4);//
 robot4.distanceCrossed_r4(r4distanceCrossed);//
  
  
  

  //dump wave files
  sc_trace_file *wf = sc_create_vcd_trace_file("ServerAndRobotTest");
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
  
  
  sc_start(1,SC_MS);
  go4.write(1);
  go3.write(1);
  go2.write(1);
  go1.write(1);
  stop1.write(0);
  stop2.write(0);
  stop3.write(0);
  stop4.write(0);
  tspeed1.write(1.8);
  tspeed2.write(1.9);
  tspeed3.write(2);
  tspeed4.write(1.7);
  sc_start(15000,SC_MS);
  tspeed1.write(2);
  tspeed3.write(2);
  tspeed2.write(1);
  tspeed4.write(1.99);
  sc_start(60000,SC_MS);
  
  
  
  sc_close_vcd_trace_file(wf);
  return 0;

}

