#include <systemc.h>
#include <FullAdder.h>

SC_MODULE(FourBitFullAdder){
sc_in<bool> a0,a1,a2,a3,b0,b1,b2,b3,cin;
sc_out<bool> s0,s1,s2,s3, carryOut;
sc_signal<bool> carry1, carry2, carry3;
  
  FullAdder* fa0; 
  FullAdder* fa1;
  FullAdder* fa2;
  FullAdder* fa3;
  
  SC_CTOR(FourBitFullAdder){
    fa0 = new FullAdder("fa0");
    fa0->a(a0);
    fa0->b(b0);
    fa0->cin(cin);
    fa0->sum(s0);
    fa0->carry_out(carry1);
    
    fa1 = new FullAdder("fa1");
    fa1->a(a1);
    fa1->b(b1);
    fa1->cin(carry1);
    fa1->sum(s1);
    fa1->carry_out(carry2);
    
    fa2 = new FullAdder("fa2");
    fa2->a(a2);
    fa2->b(b2);
    fa2->cin(carry2);
    fa2->sum(s2);
    fa2->carry_out(carry3);
    
    fa3 = new FullAdder("fa3");
    fa3->a(a3);
    fa3->b(b3);
    fa3->cin(carry3);
    fa3->sum(s3);
    fa3->carry_out(carryOut);
  }
  
};