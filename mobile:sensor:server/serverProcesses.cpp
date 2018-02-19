#include <systemc.h>
#include <server.h>

//default counter= 3840
int counter = 30; //or counter.read()
bool m1_sending = 0;
bool m2_sending = 0; 
bool m3_sending = 0;

void server :: serverProcess(){
    while (1){
        // network is 1, it is being used
        if (network.read()){
            cout << "@" << sc_time_stamp() << "ns " << "Network is busy" << endl;
        }
        // network is 0, it is free
        else{
            //4 combination for more than 1 mobile requesting
            if((m1_request)&&(m2_request)){
                cout << "m1 & m2 requested at the same time" << endl;
                //wait(12, SC_NS);
            }
            else if((m2_request)&&(m3_request)){
                cout << "m2 & m3 requested at the same time" << endl;
                //wait(23, SC_NS);
            }
            else if((m1_request)&&(m3_request)){
                cout << "m1 & m3 requested at the same time" << endl;
                //wait(13, SC_NS);
            }
            else if((m1_request)&&(m2_request)&&(m3_request)){
                cout << "m1 & m2 & m3 requested at the same time" << endl;
                //wait(32, SC_NS);
            }
            else if(m1_request){
                m1_CanSend.write(1);
                network.write(1);
                m1_sending = 1;
            }
            else if(m2_request){
                m2_CanSend.write(1);
                network.write(1);
                m2_sending = 1;
            }
            else if(m3_request){
                m3_CanSend.write(1);
                network.write(1);
                m1_sending = 1;
            }
        }
        
        if (m1_sending){
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m1_request.read() << " " << m1_sending << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                    
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m1_CanSend.write(0);
                  	m1_sending = 0;
                }
                wait(1, SC_NS);
            }
          	counter = 30; //reset counter after transmission deafult: 3840
        }
        else if (m2_sending){
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m1_request.read() << " " << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                    counter = 30; //reset counter after transmission deafult: 3840
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m2_CanSend.write(0);
                  	m2_sending = 0;
                }
                wait(1, SC_NS);
            }
        }
        else if (m3_sending){
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m1_request.read() << " " << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                    counter = 30; //reset counter after transmission deafult: 3840
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m3_CanSend.write(0);
                  	m3_sending = 0;
                }
                wait(1, SC_NS);
            }
        }
    wait(1);
    }
}