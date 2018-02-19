#include<systemc.h>

SC_MODULE(Robot){
  public:
  sc_in<double> targetSpeed;
  sc_in<bool> clock;
  sc_in<bool> go;
  sc_in<bool> stop;
  sc_out<double> speed, distance, distanceCrossed;
  sc_out<bool> crossing;
    
  void robot_SpeedProcess();
  
  
  SC_CTOR(Robot){
      SC_METHOD(robot_SpeedProcess);
      sensitive << clock.pos();
    }

  };