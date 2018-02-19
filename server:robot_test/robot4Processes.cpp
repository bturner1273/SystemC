#include <systemc.h>
#include <robot4.h>

//global vars
double distance4;
double max4;

void Robot4 :: robot_SpeedProcess(){
 	double tempSpeed = speed_r4.read();
  	double accel = .001; //acceleration at this rate ensures robot will slow down and speed up at a safe rate for people and for itself (to ensure any robot design would stay upright and resist the acceleration)
  	max4 = targetSpeed_r4.read(); //desired speed (from server)
 
  	distance_r4.write(distance_r4 + tempSpeed);
  	distance4=distance4+tempSpeed; //variable to keep track of when crossing
  distanceCrossed_r4.write(distance4);
  
  //crossing every five meters
  if(distance4 >= 5){
    crossing_r4.write(1);
    distance4 -= 5;
  }else crossing_r4.write(0);
  
  //Speed control based on stop and go inputs
  if((go_r4 && !stop_r4)){
    if(tempSpeed <= ((max4-accel)/1000)){
    tempSpeed = tempSpeed + (accel/1000);
    }else if(tempSpeed >= (max4 + accel)/1000){
      tempSpeed = tempSpeed - (accel/1000);
    }
    else{ 
      tempSpeed = (max4/1000);
    }
  }
  if((stop_r4 && !go_r4) || (stop_r4 && go_r4) || (!stop_r4 && !go_r4)){
    if(tempSpeed > (accel/1000)){
   	tempSpeed = tempSpeed - (accel/1000);
    }else tempSpeed = 0;
  }
  speed_r4.write(tempSpeed);
}