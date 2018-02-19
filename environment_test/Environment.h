#include <systemc.h>



SC_MODULE(Environment){
  public:
  //take inputs
  sc_in<int> nextPos1, nextPos2, nextPos3, nextPos4;
  sc_in<bool> clock;
  //outputs
  sc_out<bool> stop1,stop2,stop3,stop4;	//tells robot to stop
  sc_out<int> person1, person2, person3;	//location of person 1+2+3
  int p1[23]= {1,2,3,4,5,6,7,8,9,20,12,14,24,23,22,21,20,19,18,17,16,15,11};//top loop
  int p2[18]={24,27,30,33,43,42,41,40,39,38,32,29,26,19,20,21,22,23};//right loop
  int p3[16]={15,16,17,18,19,26,29,32,38,37,36,35,34,31,28,25};//left loop

  
  void walkingPeople();

  SC_CTOR(Environment)
    {
      SC_METHOD(walkingPeople);
      sensitive << clock.pos();
    }

  };