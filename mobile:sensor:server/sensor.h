#include <systemc.h>
SC_MODULE(sensor){
    sc_in<bool> clock;
    sc_out<int> x,y;
    
    void generateSample();
    
    SC_CTOR(sensor){
        SC_THREAD(generateSample);
        sensitive << clock.pos();
    }
};