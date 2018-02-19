#include <systemc.h>
#include <HalfAdder.h>

void HalfAdder :: function(){
    sum = a ^ b;
    carry_out = a & b;
  }