
#include <systemc.h>
#include <mobile.h>
#include <stdio.h>
using namespace std;


int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
void mobile :: determineRoiInfo(){
    int tempX = x.read(),
  	  tempY = y.read();
     //ROI2 and ROI3 and ROI4 check
  if((tempX >= 40 && tempX <= 670) && (tempY >= 550 && tempY <= 950) && (tempX >= 20 && tempX <= 470) && (tempY >= 600 && tempY <= 900) && (tempX >= 50 && tempX <= 370) && (tempY >= 450 && tempY <= 1000)){
    if(count1 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    if(count2 == 0 || count3 == 0 || count4 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at the region corresponding to ROI2, ROI3 and ROI4\n";
    }
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
   if(count3 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI3\n";
    }else if(count1 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    if(count4 == 0 && count2 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at the region corresponding to both ROI2 and ROI4\n";
    }
    else if(count2 == 0 && !(count4 == 0)){
      cout << "@" << sc_time_stamp() << " person was looking at region 4 then began looking at the region corresponding to both ROI2 and ROI4\n";
    }
  	else if(count4 == 0 && !(count2 == 0)){
      cout << "@" << sc_time_stamp() << " person was looking at region 2 then began looking at the region corresponding to both ROI2 and ROI4\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI2\n";
    }else if(count1 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    if(count4 == 0 && count3 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at the region corresponding to both ROI3 and ROI4\n";
    }
    else if(count3 == 0 && !(count4 == 0)){
      cout << "@" << sc_time_stamp() << " person was looking at region 4 then began looking at the region corresponding to both ROI3 and ROI4\n";
    }
  	else if(count4 == 0 && !(count3 == 0)){
      cout << "@" << sc_time_stamp() << " person was looking at region 3 then began looking at the region corresponding to both ROI3 and ROI4\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI2\n";
    }else if(count3 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI3\n";
    }else if(count4 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI4\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    
    if(count1 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at ROI1\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count3 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI3\n";
    }else if(count4 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI4\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    
    if(count2 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at ROI2\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count2 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI2\n";
    }else if(count4 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI4\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    
    if(count3 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at ROI3\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI2\n";
    }else if(count3 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI3\n";
    }else if(count1 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count5 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI5\n";
    }
    
    if(count4 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at ROI4\n";
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
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI2\n";
    }else if(count3 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI3\n";
    }else if(count1 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI1\n";
    }else if(count4 != 0){
      cout << "@" << sc_time_stamp() << " person stopped looking at ROI4\n";
    }
    
    if(count5 == 0){
      cout << "@" << sc_time_stamp() << " person began looking at ROI5\n";
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