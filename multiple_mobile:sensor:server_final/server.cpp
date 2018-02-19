#include <systemc.h>
#include <server.h>
#include <fstream>
#include <iostream>
//default counter= 3840
int counter = 30; //or counter.read()
bool m1_sending = 0;
bool m2_sending = 0; 
bool m3_sending = 0;
ofstream myfile("PacketTimes.txt");
void server :: serverProcess(){
    while(1){
        // network is 1, it is being used
        if (network.read()){
            //cout << "@" << sc_time_stamp() << "ns " << "Network is busy" << endl;
        }
        // network is 0, it is free
        else{
            //4 combination for more than 1 mobile requesting
            if((m1_request)&&(m2_request)){
                myfile << "@" << sc_time_stamp() << " m1 & m2 requested at the same time" << endl;
                wait(12, SC_MS);
            }
            else if((m2_request)&&(m3_request)){
                myfile << "@" << sc_time_stamp() << " m2 & m3 requested at the same time" << endl;
                wait(23, SC_MS);
            }
            else if((m1_request)&&(m3_request)){
                myfile << "@" << sc_time_stamp() << " m1 & m3 requested at the same time" << endl;
                wait(13, SC_MS);
            }
            else if((m1_request)&&(m2_request)&&(m3_request)){
                myfile << "@" << sc_time_stamp() << " m1 & m2 & m3 requested at the same time" << endl;
                wait(32, SC_MS);
            }
            else if(m1_request){
              myfile << "@" << sc_time_stamp() << " m1 requested to send packet" << endl;
                m1_CanSend.write(1);
                network.write(1);
                m1_sending = 1;
            }
            else if(m2_request){
              myfile << "@" << sc_time_stamp() << " m2 requested to send packet" << endl;
                m2_CanSend.write(1);
                network.write(1);
                m2_sending = 1;
            }
            else if(m3_request){
              myfile << "@" << sc_time_stamp() << " m3 requested to send packet" << endl;
                m3_CanSend.write(1);
                network.write(1);
                m3_sending = 1;
            }
        }
        
        if (m1_sending){
          if(counter == 30){ 
          myfile << "@" << sc_time_stamp() << " m1 began sending packet" << endl;
          }
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                //cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m1_request.read() << " " << m1_sending << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                    myfile << "@" << sc_time_stamp() << " m1 finished sending packet" << endl;
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m1_CanSend.write(0);
                  	m1_sending = 0;
                }
                wait(1, SC_MS);
            }
          	counter = 30; //reset counter after transmission deafult: 3840
        }
        else if (m2_sending){
          if(counter = 30){
            myfile << "@" << sc_time_stamp() << " m2 began sending packet" << endl;
          }
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                //cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m2_request.read() << " " << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                  myfile << "@" << sc_time_stamp() << " m2 finished sending packet" << endl;
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m2_CanSend.write(0);
                  	m2_sending = 0;
                }
                wait(1, SC_MS);
            }
          	counter = 30; //reset counter after transmission deafult: 3840
        }
        else if (m3_sending){
          if(counter == 30){
            myfile << "@" << sc_time_stamp() << " m3 began sending packet" << endl;
          }
            while((counter>0)){
                //packet receiving for phase 3
                //phase 2: only wait
                //cout << "@" << sc_time_stamp() << " " << counter << " " << network.read() << " " << m3_request.read() << " " << endl;  
                counter--;
                //packet_counter is not used in phase 2
                //packet_counter.write(counter);
                if(counter==0){
                 myfile << "@" << sc_time_stamp() << " m3 finished sending packet" << endl;
                    network.write(0); //clear network block
                    //reset CanSend signal, 0 = cannot be sent
                    m3_CanSend.write(0);
                  	m3_sending = 0;
                }
                wait(1, SC_MS);
            }
          	counter = 30; //reset counter after transmission deafult: 3840
        }
    wait(1, SC_MS);
    }
}
