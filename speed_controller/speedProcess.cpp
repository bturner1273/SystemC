#include <systemc.h>
#include "speedController.h"

void speedController :: speedController_prc(){
  if((accel && !brake) && speed < 128){
    count++;
    if(count < 9){
     speed = speed + 2; 
    }
  }
  if(accel && brake){
    count = 0;
    if(speed > 2){
      speed = speed - 2;
    }else speed = 0;
  }
  if(!accel && brake){
    count = 0;
    if(speed > 4){
      speed = speed - 4;
    }else speed = 0;
  }
  if(!accel && !brake){
    count = 0;
    if(speed > 1){
      speed = speed - 1;
    }else speed = 0;
  }
  if(reset){
   count = 0;
   speed = 0;
  }
}