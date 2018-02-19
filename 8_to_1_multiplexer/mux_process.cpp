#include <systemc.h>
#include <8to1Multiplexer.h>

void Multiplexer :: mux_process(){
  if(c2.read() == 0 && c1.read() == 0 && c0.read() == 0){
    dataOut.write(i0);
  }
  if(c2.read() == 0 && c1.read() == 0 && c0.read() == 1){
    dataOut.write(i1);
  }
  if(c2.read() == 0 && c1.read() == 1 && c0.read() == 0){
    dataOut.write(i2);
  }
  if(c2.read() == 0 && c1.read() == 1 && c0.read() == 1){
    dataOut.write(i3);
  }
  if(c2.read() == 1 && c1.read() == 0 && c0.read() == 0){
    dataOut.write(i4);
  }
  if(c2.read() == 1 && c1.read() == 0 && c0.read() == 1){
    dataOut.write(i5);
  }
  if(c2.read() == 1 && c1.read() == 1 && c0.read() == 0){
    dataOut.write(i6);
  }
  if(c2.read() == 1 && c1.read() == 1 && c0.read() == 1){
    dataOut.write(i7);
  }
}