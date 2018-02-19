#include <systemc.h>
#include <exor.h>
#include <and.h>



SC_MODULE(HalfAdder){
  sc_in<bool>a,b;
  sc_out<bool>sum,carry;
  
  
  
AND* and1;
EXOR* exor;

  SC_CTOR(HalfAdder){ //don't name any modules and!!
   and1 = new AND("and");
    and1 -> a(a);
    and1 -> b(b);
    and1 -> aANDb(carry);
    
    
   exor = new EXOR("exor");
    exor -> a(a);
    exor -> b(b);
    exor -> aEXORb(sum);
  }
};