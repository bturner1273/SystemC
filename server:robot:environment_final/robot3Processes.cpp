#include <systemc.h>
#include "robot3.h"

//global vars
double distance3;
double max3;

void Robot3 :: robot_SpeedProcess(){
 	double tempSpeed = speed_r3.read();
  	double accel = .001; //acceleration at this rate ensures robot will slow down and speed up at a safe rate for people and for itself (to ensure any robot design would stay upright and resist the acceleration)
  int factor = 8; //decellerates 5* as fast
  	max3 = targetSpeed_r3.read(); //desired speed (from server)
 
  	distance_r3.write(distance_r3 + tempSpeed);
  	distance3=distance3+tempSpeed; //variable to keep track of when crossing
  distanceCrossed_r3.write(distance3);
  
  //crossing every five meters
  if(distance3 >= 5){
    crossing_r3.write(1);
    distance3 -= 5;
  }else crossing_r3.write(0);
  
  //Speed control based on stop and go inputs
  if((go_r3 && !stop_r3)){
    if(tempSpeed <= ((max3-accel)/1000)){
    tempSpeed = tempSpeed + (accel/1000);
    }else if(tempSpeed >= (max3 + accel)/1000){
      tempSpeed = tempSpeed - ((factor*accel)/1000);
    }
    else{ 
      tempSpeed = (max3/1000);
    }
  }
  if((stop_r3 && !go_r3) || (stop_r3 && go_r3) || (!stop_r3 && !go_r3)){
    if(tempSpeed > ((factor*accel)/1000)){
   	tempSpeed = tempSpeed - ((factor*accel)/1000);
    }else tempSpeed = 0;
  }
  speed_r3.write(tempSpeed);
}