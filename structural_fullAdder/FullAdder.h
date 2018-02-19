#include <systemc.h>
#include <HalfAdder.h>
#include <or.h>

SC_MODULE(FullAdder){
	sc_in<bool> a, b, cin;
  	sc_out<bool> sum, carry_out;
  	sc_signal<bool> sig_sum, sig_carry1, sig_carry2;
  
  OR* or1;
  HalfAdder* ha1;
  HalfAdder* ha2;
  
  SC_CTOR(FullAdder){
    ha1 = new HalfAdder("HalfAdder1");
    ha1->a(a);
    ha1->b(b);
    ha1->sum(sig_sum);
    ha1->carry(sig_carry1);
    
    ha2 = new HalfAdder("HalfAdder2");
    ha2->a(sig_sum);
    ha2->b(cin);
    ha2->sum(sum);
    ha2->carry(sig_carry2);

    or1 = new OR("ORGate");
    or1->a(sig_carry1);
    or1->b(sig_carry2);
    or1->aORb(carry_out);
  }
  
  
};