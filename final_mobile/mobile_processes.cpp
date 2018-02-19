
#include <systemc.h>
#include <mobile.h>
#include <fstream>
#include <iostream>
using namespace std;

ofstream myfile("TimesAtEachPosition.txt");
int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
void mobile :: determineRoiInfo(){
    int tempX = x.read(),
  	  tempY = y.read();
     //ROI2 and ROI3 and ROI4 check
  if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900) && (tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }else if(count4 != 0){
       myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
      myfile << "@" << sc_time_stamp() << " person began looking at the region corresponding to ROI2, ROI3 and ROI4";
    count4++;
    count3++;
    count2++;
    count1 = 0; 
    count5 = 0;
    t2.write((count2*.004));
    t4.write((count4*.004));
    t3.write((count3*.004));
    ROI1.write(0);
    ROI2.write(1);
    ROI3.write(1);
    ROI4.write(1);
    ROI5.write(0);
  }
  
  //ROI2 and ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }else if(count4 != 0){
       myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    if(count4 == 0 && count2 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at the region corresponding to both ROI2 and ROI4";
    }
    else if(count2 == 0 && !(count4 == 0)){
      myfile << "@" << sc_time_stamp() << " person was looking at region 4 then began looking at the region corresponding to both ROI2 and ROI4";
    }
  	else if(count4 == 0 && !(count2 == 0)){
      myfile << "@" << sc_time_stamp() << " person was looking at region 2 then began looking at the region corresponding to both ROI2 and ROI4";
    }
    count4++;
    count2++;
    count3 = 0;
    count1 = 0; 
    count5 = 0;
    t4.write((count4*.004));
    t2.write((count2*.004));
    ROI1.write(0);
    ROI2.write(1);
    ROI3.write(0);
    ROI4.write(1);
    ROI5.write(0);
  }
   //ROI3 and ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }else if(count4 != 0){
       myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    if(count4 == 0 && count3 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at the region corresponding to both ROI3 and ROI4";
    }
    else if(count3 == 0 && !(count4 == 0)){
      myfile << "@" << sc_time_stamp() << " person was looking at region 4 then began looking at the region corresponding to both ROI3 and ROI4";
    }
  	else if(count4 == 0 && !(count3 == 0)){
      myfile << "@" << sc_time_stamp() << " person was looking at region 3 then began looking at the region corresponding to both ROI3 and ROI4";
    }
    count4++;
    count3++;
    count2 = 0;
    count1 = 0; 
    count5 = 0;
    t4.write((count4*.004));
    t3.write((count3*.004));
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(1);
    ROI4.write(1);
    ROI5.write(0);
  }
  
  //ROI1 check
  else if((tempX >= 20 && tempX <= 50) && (tempY >= 320 && tempY <= 400)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count4 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI4";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    
    if(count1 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at ROI1";
    }
    count1++;
    count2 = 0;
    count3 = 0;
    count4 = 0; 
    count5 = 0;
    t1.write((count1*.004));
    ROI1.write(1);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
  }

//ROI2 check
   else if((tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count4 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI4";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    
    if(count2 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at ROI2";
    }
    count2++;
    count1 = 0;
    count3 = 0;
    count4 = 0; 
    count5 = 0;
    t2.write((count2*.004));
    ROI1.write(0);
    ROI2.write(1);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(0);
  }
  
  //ROI3 check
 else if((tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900)){
    if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count4 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI4";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    
    if(count3 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at ROI3";
    }
    count3++;
    count1 = 0;
    count2 = 0;
    count4 = 0; 
    count5 = 0;
    t3.write((count3*.004));
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(1);
    ROI4.write(0);
    ROI5.write(0);
  }
  
  //ROI4 check
  else if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count5 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI5";
    }
    
    if(count4 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at ROI4";
    }
    count4++;
    count2 = 0;
    count3 = 0;
    count1 = 0; 
    count5 = 0;
    t4.write((count4*.004));
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(1);
    ROI5.write(0);
  }
    //ROI5 check
  else if((tempX >= 680 && tempX <= 700) && (tempY == 1000)){
    if(count2 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI2";
    }else if(count3 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI3";
    }else if(count1 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI1";
    }else if(count4 != 0){
      myfile << "@" << sc_time_stamp() << " person stopped looking at ROI4";
    }
    
    if(count5 == 0){
      myfile << "@" << sc_time_stamp() << " person began looking at ROI5";
    }
    count5++;
    count2 = 0;
    count3 = 0;
    count1 = 0; 
    count4 = 0;
    t5.write((count5*.004));
    ROI1.write(0);
    ROI2.write(0);
    ROI3.write(0);
    ROI4.write(0);
    ROI5.write(1);
  } 
  
}