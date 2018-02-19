#include <systemc.h>



SC_MODULE(Environment){
  public:
  //take inputs
  sc_in<int> nextPos1, nextPos2, nextPos3, nextPos4;
  sc_in<bool> clock;
  //outputs
  sc_out<bool> stop1,stop2,stop3,stop4;	//tells robot to stop
  sc_out<int> person1, person2, person3;	//location of person 1+2+3
  

  
  void walkingPeople();

  SC_CTOR(Environment)
    {
      SC_METHOD(walkingPeople);
      sensitive << clock.pos();
    }

  };