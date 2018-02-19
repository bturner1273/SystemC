 #include <systemc.h>
#include "robot2.h"

//global vars
double distance2;
double max2;

void Robot2 :: robot_SpeedProcess(){
 	double tempSpeed = speed_r2.read();
  	double accel = .001; //acceleration at this rate ensures robot will slow down and speed up at a safe rate for people and for itself (to ensure any robot design would stay upright and resist the acceleration)
  int factor = 8; //this is how much faster we are gonna decellerate than accelerate
  	max2 = targetSpeed_r2.read(); //desired speed (from server)
 
  	distance_r2.write(distance_r2 + tempSpeed);
  	distance2=distance2+tempSpeed; //variable to keep track of when crossing
  distanceCrossed_r2.write(distance2);
  
  //crossing every five meters
  if(distance2 >= 5){
    crossing_r2.write(1);
    distance2 -= 5;
  }else crossing_r2.write(0);
  
  //Speed control based on stop and go inputs
  if((go_r2 && !stop_r2)){
    if(tempSpeed <= ((max2-accel)/1000)){
    tempSpeed = tempSpeed + (accel/1000);
    }else if(tempSpeed >= (max2 + accel)/1000){
      tempSpeed = tempSpeed - ((factor*accel)/1000);
    }
    else{ 
      tempSpeed = (max2/1000);
    }
  }
  if((stop_r2 && !go_r2) || (stop_r2 && go_r2) || (!stop_r2 && !go_r2)){
    if(tempSpeed > ((factor*accel)/1000)){
   	tempSpeed = tempSpeed - ((factor*accel)/1000);
    }else tempSpeed = 0;
  }
  speed_r2.write(tempSpeed);
}