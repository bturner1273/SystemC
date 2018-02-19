#include <systemc.h>

SC_MODULE(Robot3){
  public:
  sc_in<double> targetSpeed_r3;
  sc_in<bool> clock;
  sc_in<bool> go_r3;
  sc_in<bool> stop_r3;
  sc_out<double> speed_r3, distance_r3, distanceCrossed_r3;
  sc_out<bool> crossing_r3;
    
  void robot_SpeedProcess();
  
  
  SC_CTOR(Robot3){
      SC_METHOD(robot_SpeedProcess);
      sensitive << clock.pos();
    }

  };