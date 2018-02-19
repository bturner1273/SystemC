#include <systemc.h>

SC_MODULE(server){
    sc_in<bool> clock;
    // receive request to send signal
    sc_in<bool> m1_request;
    sc_in<bool> m2_request;
    sc_in<bool> m3_request;
    //sc_fifo<int> server_packet(3840);
    
    sc_out<bool> network; //0 is free, 1 is being used
    //packet_counter siganl is not used in phase2
    //sc_out<int> packet_counter: //3480, count down 
    sc_out<bool> m1_CanSend;
    sc_out<bool> m2_CanSend;
    sc_out<bool> m3_CanSend;
    
    
    void serverProcess();
    //void packet_receiving();
    
    SC_CTOR(server){
        SC_THREAD(serverProcess);
        sensitive << clock.pos() << m1_request << m2_request << 		m3_request;
    }
};