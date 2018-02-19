SC_MODULE(speedController){
  sc_in<bool> accel, brake, reset, clock;
  sc_out<int> speed;
  int count = 0;
  
  void speedController_prc();
  
  SC_CTOR(speedController){
   SC_METHOD(speedController_prc);
   sensitive << clock.pos();
  }
  
  
};