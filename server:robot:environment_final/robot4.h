#include <systemc.h>
SC_MODULE(Robot4){
  public:
  sc_in<double> targetSpeed_r4;
  sc_in<bool> clock;
  sc_in<bool> go_r4;
  sc_in<bool> stop_r4;
  sc_out<double> speed_r4, distance_r4, distanceCrossed_r4;
  sc_out<bool> crossing_r4;
    
  void robot_SpeedProcess();
  
  
  SC_CTOR(Robot4){
      SC_METHOD(robot_SpeedProcess);
      sensitive << clock.pos();
    }

  };