#include <systemc.h>
#include <string.h>
SC_MODULE(mobile){
  sc_in<bool> clock;
  sc_in<int> x, y;
  sc_out<bool> ROI1,ROI2,ROI3,ROI4,ROI5;
  sc_out<double> t1,t2,t3,t4,t5;
  
  void determineRoiInfo();
  
  SC_CTOR(mobile){
    SC_METHOD(determineRoiInfo);
    sensitive << clock.pos();
  }
};

//If we are going to parameterize the filename it will look something like this

/*
SC_HAS_PROCESS(mobile);
  mobile(sc_module_name name, const char* filename) : sc_module(name), _filename(filename){

	public:
	const char* _filename;
    */