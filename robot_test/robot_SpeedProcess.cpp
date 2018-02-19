#include <systemc.h>
#include "Robot.h"

//global vars
double distance1;
double max;

void Robot :: robot_SpeedProcess(){
 	double tempSpeed = speed.read();
  	double accel = .001;//acceleration at this rate ensures robot will slow down and speed up at a safe rate for people and for itself (to ensure any robot design would stay upright and resist the acceleration)
  	int factor = 5;//factor will the ratio of how much faster we want the robot to decellerate than accelerate
  	max = targetSpeed.read(); //desired speed (from server)
 
  	distance.write(distance + tempSpeed);
  	distance1=distance1+tempSpeed; //variable to keep track of when 									crossing
  distanceToNextCrossing.write(distance1);
  
  //crossing every five meters
  if(distance1 >= 5){
    crossing.write(1);
    distance1 -= 5;
  }else crossing.write(0);
  
  //Speed control based on stop and go inputs
  if((go && !stop)){
    if(tempSpeed <= ((max-accel)/1000)){
    tempSpeed = tempSpeed + (accel/1000);
    }else if(tempSpeed >= (max + accel)/1000){
      tempSpeed = tempSpeed - ((factor*accel)/1000);
    }
    else{ 
      tempSpeed = (max/1000);
    }
  }
  if((stop && !go) || (stop && go) || (!stop && !go)){
    if(tempSpeed > ((factor*accel)/1000)){
   	tempSpeed = tempSpeed - ((factor*accel)/1000);
    }else tempSpeed = 0;
  }
  speed.write(tempSpeed);
}
