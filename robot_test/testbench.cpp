// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <Robot.h>

int sc_main(int argc, char* argv[]){
  sc_clock clock("clock", 1, SC_MS);
  sc_signal<bool> go, stop;
  sc_signal<double> speed, distance, distanceToNextCrossing;
  sc_signal<double> targetSpeed;
  sc_signal<bool> crossing;
  
  
  Robot robot("robot");
  robot.go(go);
  robot.stop(stop);
  robot.clock(clock);
  robot.speed(speed);
  robot.distance(distance);
  robot.targetSpeed(targetSpeed);
  robot.crossing(crossing);
  robot.distanceToNextCrossing(distanceToNextCrossing);
  
  sc_trace_file *wf = sc_create_vcd_trace_file("Robot");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, go, "go");
  sc_trace(wf, stop, "stop");
  sc_trace(wf, speed, "speed");
  sc_trace(wf, distance, "distance");
  sc_trace(wf, targetSpeed, "targetSpeed");
  sc_trace(wf, crossing, "crossing");
  sc_trace(wf, distanceToNextCrossing, "distanceToNextCrossing");
 
  
  sc_start(10,SC_MS);
  go.write(1);
  stop.write(0);
  targetSpeed.write(2);
  sc_start(5000,SC_MS);
  targetSpeed.write(0);
  sc_start(10000,SC_MS);

  
  sc_close_vcd_trace_file(wf);
  return 0;
}
  
