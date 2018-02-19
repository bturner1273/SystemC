#include <systemc.h>
#include <mobile.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int tupleCount = 0;
int packetCount = 0;

int count234 = 0, count24 = 0, count34 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
void mobile :: determineRoiInfo(){
    int tempX = x.read(),
  	  tempY = y.read();
     //ROI2 and ROI3 and ROI4 check
  if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900) && (tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    count24 = 0;
    count34 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    if(count234 == 0){ 
      tupleCount++;
      count234++;
    }
    
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(1);
  }
  
  //ROI2 and ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    count234 = 0;
    count34 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    if(count24 == 0){ 
      tupleCount++;
      count24++;
    }
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(1);
    ROI34.write(0);
    ROI234.write(0);
  }
   //ROI3 and ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900)){
    count24 = 0;
    count234 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    if(count34 == 0){ 
      tupleCount++;
      count34++;
    }
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(1);
    ROI234.write(0);
  }
  
  //ROI1 check
  else if((tempX >= 20 && tempX <= 50) && (tempY >= 320 && tempY <= 400)){
    count24 = 0;
    count34 = 0;
    count234 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    if(count1 == 0){ 
      tupleCount++;
      count1++;
    }
    ROI1.write(1);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(0);
  }

//ROI2 check
   else if((tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
       count24 = 0;
    count34 = 0;
    count1 = 0;
    count234 = 0;
    count3 = 0;
    count4 = 0;
    count5 = 0;
    if(count2 == 0){ 
      tupleCount++;
      count2++;
    }
    ROI1.write(0);
    ROI2.write(1);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(0);
  }
  
  //ROI3 check
 else if((tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900)){
    count24 = 0;
    count34 = 0;
    count1 = 0;
    count2 = 0;
    count234 = 0;
    count4 = 0;
    count5 = 0;
    if(count3 == 0){ 
      tupleCount++;
      count3++;
    }
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(1);
    ROI4.write(0);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(0);
  }
  
  //ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950)){
    count24 = 0;
    count34 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count234 = 0;
    count5 = 0;
    if(count4 == 0){ 
      tupleCount++;
      count4++;
    }
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(1);
    ROI5.write(0);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(0);
  }
    //ROI5 check
  else if((tempX >= 680 && tempX <= 700) && (tempY == 1000)){
    count24 = 0;
    count34 = 0;
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    count234 = 0;
    if(count5 == 0){ 
      tupleCount++;
      count5++;
    }
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(1);
    ROI24.write(0);
    ROI34.write(0);
    ROI234.write(0);
  } 
  
  if(tupleCount == 20){
    sendRequest.write(1);
    if(!network){
      if(canSend){
        packetCount++;
      	cout << "mobile sent packet " << packetCount << endl;
      }
    }
    tupleCount = 0;
  }else{
   	sendRequest.write(0); 
  }
  
}