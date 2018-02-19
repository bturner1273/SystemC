
SC_MODULE(Robot2){
  public:
  sc_in<double> targetSpeed_r2;
  sc_in<bool> clock;
  sc_in<bool> go_r2;
  sc_in<bool> stop_r2;
  sc_out<double> speed_r2, distance_r2, distanceCrossed_r2;
  sc_out<bool> crossing_r2;
    
  void robot_SpeedProcess();
  
  
  SC_CTOR(Robot2){
      SC_METHOD(robot_SpeedProcess);
      sensitive << clock.pos();
    }

  };