#include <systemc.h>

SC_MODULE(Server){
  sc_in<bool> clock;
  sc_in<bool> crossing1, crossing2, crossing3, crossing4;//tells us when each robot crosses to the next positions in their paths
  
  sc_in<double> 		r1speed,r2speed,r3speed,r4speed,r1distance,r2distance,r3distance,r4distance,r1distanceToCross,r2distanceToCross, r3distanceToCross, r4distanceToCross;//distance and speed inputs for each robot
  
  sc_out<bool> go1,go2,go3,go4,stop1,stop2,stop3,stop4;//boolean stop and go outs for each robot
  
  sc_out<double> tspeed1, tspeed2, tspeed3,tspeed4; //target speed outputs
  
  sc_out<int> currentPos1, nextPos1, currentPos2, nextPos2, currentPos3, nextPos3, currentPos4, nextPos4; //current and next position output of each robot

  
  void goAndStop();
  void updateRobotPositions();
  
  SC_CTOR(Server){
    SC_METHOD(goAndStop);
    sensitive << clock.pos();
    SC_METHOD(updateRobotPositions);
    sensitive<<crossing1.pos()<<crossing2.pos()<<crossing3.pos()<<crossing4.pos(); //updateRobotPositions ISN'T SENSITIVE TO CLOCK!!
    
    
  }
  
  
  
  
};