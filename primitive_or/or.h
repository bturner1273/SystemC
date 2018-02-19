//include systemc and all headers
#include <systemc.h>

//start defining module
SC_MODULE(OR){
  //define ins and outs
  sc_in<bool> a, b;
  sc_out<bool> aORb;
  //declare processes
  void or_process();
  //constructor
  SC_CTOR(OR){
    //define method/thread sensitivities
    //instatiate any modules that are going to be
    //in this module
    SC_METHOD(or_process);
    sensitive << a << b;
  } 
};



/*

SC_HAS_PROCESS(OR);
OR(sc_module_name name, int number) : sc_module(name), _number(number){
SC_METHOD(or_process);
sensitive << a << b;
}

public:
int _number;

*/