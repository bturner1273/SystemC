#include<systemc.h>
#include<HalfAdder.h>

SC_MODULE(FullAdder){
  sc_in<bool> a, b, cin;
  sc_out<bool> sum, carry_out;
  sc_signal<bool> sig_sum, sig_carry1, sig_carry2;
  
  void FA_OR_Process(){
   carry_out.write(sig_carry1 | sig_carry2); 
  }
  
  HalfAdder* ha1;
  HalfAdder* ha2;
  
  SC_CTOR(FullAdder){ 
    ha1 = new HalfAdder("ha1");
    ha1 -> a(a);
    ha1 -> b(b);
    ha1 -> sum(sig_sum);
    ha1 -> carry(sig_carry1);
    
    ha2 = new HalfAdder("ha2");
    ha2 -> a(sig_sum);
    ha2 -> b(cin);
    ha2 -> sum(sum);
    ha2 -> carry(sig_carry2);
    
    SC_METHOD(FA_OR_Process);
    sensitive << sig_carry1 << sig_carry2;
  }
};