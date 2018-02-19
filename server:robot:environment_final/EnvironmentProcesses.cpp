#include <Environment.h>
#include <systemc.h>

 void Environment :: walkingPeople()
  {
   int p1[23]= {1,2,3,4,5,6,7,8,9,20,12,14,24,23,22,21,20,19,18,17,16,15,11};//top loop
  int p2[18]={24,27,30,33,43,42,41,40,39,38,32,29,26,19,20,21,22,23};//right loop
  int p3[16]={15,16,17,18,19,26,29,32,38,37,36,35,34,31,28,25};//left loop
    static int c1=0,c2=0,c3=0,c4=0;	//count variables
	static double speed=1.4/1000;//avg human walking speed 											1.4(m/s)
	static double speedCounter=0;
  speedCounter=speedCounter+speed;
  //Robot 1
  if(nextPos1==p1[c1]||nextPos1==p2[c2]||nextPos1==p3[c3])//only may coming in contact with 2
  {
    stop1.write(1);
  }
  else
  {
    stop1.write(0);
  }
  //Robot2
  if(nextPos2==p1[c1]||nextPos2==p2[c2]||nextPos2==p3[c3])
  {
    stop2.write(1);
  }
  else
  {
    stop2.write(0);
  }
  //Robot 3
  if(nextPos3==p1[c1]||nextPos3==p2[c2]||nextPos3==p3[c3])
  {
    stop3.write(1);
  }
  else
  {
    stop3.write(0);
  }
  //Robot 4
  if(nextPos4==p1[c1]||nextPos4==p2[c2]||nextPos4==p3[c3])
  {
    stop4.write(1);
  }
  else
  {
    stop4.write(0);
  }

  person1.write(p1[c1]);
  person2.write(p2[c2]);
  person3.write(p3[c3]);

  if(speedCounter>=5)//since they start and go at the same pace they 
  {					//they cross at the same times
    
    //check to see if end of persons path
    if(c1>=22)
    {
      c1=-1;
    }
    if(c2>=17)
    {
      c2=-1;
    }
    if(c3>=15)
    {
      c3=-1;
    }
    //next grid
    c1=c1+1;
    c2=c2+1;
    c3=c3+1;
    
 //  cout<<"Count check \nc1: "<<c1<<" c2:"<<c2<<" c3:"<< c3;
    //reset counter
    speedCounter=0;
  }

}  
