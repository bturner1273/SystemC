#include <systemc.h>
#include "pulseCounter.h"

int temp;

void pulseCounter :: start(){
  if(!overflow){
    canStart = true;
  }else canStart = false;
}

void pulseCounter :: stop(){ 
  canStart = 0;
}
void pulseCounter :: count(){
  temp = counter.read();
  if(canStart && (temp <= 32)){
    temp = temp + 1;
    canStart = 1;
  }else{
   temp = 0;
  }
  if(temp > 32){
    overflow = 1;
    canStart = 0;
  }
  if(reset){
   temp = 0;
   overflow = 0;
  }
  counter = temp; 
}