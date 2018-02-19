#include <server.h>
#include <systemc.h>
#include <grid.h>

bool done1, done2, done3, done4;
int count = 0;
int count1 = 0,count2 = 0,count3 = 0,count4 = 0; //count of # of times robot has updated position

void Server :: goAndStop(){
  //as default we write go to all the robots
  //if we write stop to a robot it will stop just
  //the same as if we had never written go to it
  go1.write(1);
  go2.write(1);
  go3.write(1);
  go4.write(1);
  
  
  
  //end of path conditions for every robot
  int currentpos1 = currentPos1.read();
  int nextpos1 = nextPos1.read();
  if(currentpos1 == nextpos1){
    go1.write(0);
  }
  if(currentPos2 == nextPos2){
    go2.write(0);
  }
  if(currentPos3 == nextPos3){
    go3.write(0);
  }
  if(currentPos4 == nextPos4){
    go4.write(0);
  }
}

void Server :: updateRobotPositions(){
static int pathArray1[13] = {3,4,5,6,7,8,9,10,12,14,24,23,22};
static int pathArray2[13] = {30,27,24,23,22,21,20,19,26,29,32,38,39};
static int pathArray3[11] = {23,22,21,20,19,18,17,16,15,13,11};
static int pathArray4[14] = {34,31,28,25,15,16,17,18,19,26,29,32,38,37};
int sizePath1 = 13;
int sizePath2 = 13;
int sizePath3 = 11;
int sizePath4 = 14;

  grid map;
  map.makeGrid();
  if(count == 0 && !(crossing1 || crossing2 || crossing3 || crossing4)){
    count++;
    map.setPos1(pathArray1[0]);
	currentPos1 = pathArray1[0]; 
	nextPos1 = pathArray1[1];
    map.setPos2(pathArray2[0]);
    currentPos2 = pathArray2[0];
    nextPos2 = pathArray2[1]; 
    map.setPos3(pathArray3[0]);
    currentPos3 = pathArray3[0];
    nextPos3 = pathArray3[1];
    map.setPos4(pathArray4[0]);
    currentPos4 = pathArray4[0];
    nextPos4 = pathArray4[1];
    cout << "@" << sc_time_stamp() << " all robots at initial positions:\n";
    map.print();
  }else{
  if(crossing1 && !done1){
    if(count1 <= sizePath1-2){
     count1++;
    map.setPos4(pathArray4[count4]);
    map.setPos2(pathArray2[count2]);
    map.setPos3(pathArray3[count3]);
    map.setPos1(pathArray1[count1]);
    currentPos1.write(pathArray1[count1]);
    nextPos1.write(pathArray1[count1+1]);
     cout << "@" << sc_time_stamp() << " robot1 crossed from position " << currentPos1.read() <<" to position " << nextPos1.read() << "\n";
      map.print();
    }else{
      const int z = pathArray1[sizePath1-1];
      map.setPos4(pathArray4[count4]);
    map.setPos2(pathArray2[count2]);
    map.setPos3(pathArray3[count3]);
      map.setPos1(pathArray1[count1]);
      currentPos1.write(z);
      nextPos1.write(z);
      done1 = true;
      cout << "@" << sc_time_stamp() << " robot1 rests at final position " << pathArray1[sizePath1-1] << "\n";
      map.print();
    } 
  }
  if(crossing2 && !done2){
     if(count2 <= sizePath2-2){
    count2++;
       map.setPos1(pathArray1[count1]);
    map.setPos4(pathArray4[count4]);
    map.setPos3(pathArray3[count3]);
    map.setPos2(pathArray2[count2]);
    currentPos2.write(pathArray2[count2]);
    nextPos2.write(pathArray2[count2+1]);
       cout << "@" << sc_time_stamp() << " robot2 crossed from position " << currentPos2.read() <<" to position " << nextPos2.read() << "\n";
      map.print();
    }else{
       const int b = pathArray2[sizePath2-1];
      map.setPos1(pathArray1[count1]);
    map.setPos4(pathArray4[count4]);
    map.setPos3(pathArray3[count3]);
      map.setPos2(pathArray2[count2]);
      currentPos2.write(b);
      nextPos2.write(b);
      done2 = true;
     cout << "@" << sc_time_stamp() << " robot2 rests at final position " << pathArray2[sizePath2-1] << "\n";
      map.print();
    }
  }
  if(crossing3 && !done3){
     if(count3<= sizePath3-2){
    count3++;
       map.setPos1(pathArray1[count1]);
    map.setPos2(pathArray2[count2]);
    map.setPos4(pathArray4[count4]);
    map.setPos3(pathArray3[count3]);
    currentPos3.write(pathArray3[count3]);
    nextPos3.write(pathArray3[count3+1]); 
       cout << "@" << sc_time_stamp() << " robot3 crossed from position " << currentPos3.read() <<" to position " << nextPos3.read() << "\n";
      map.print();
    }else{
      const int c = pathArray3[sizePath3-1];
      map.setPos1(pathArray1[count1]);
    map.setPos2(pathArray2[count2]);
    map.setPos4(pathArray4[count4]);
      map.setPos3(pathArray3[count3]);
      currentPos3.write(c);
      nextPos3.write(c);
      done3 = true;
       cout << "@" << sc_time_stamp() << " robot3 rests at final position " << pathArray3[sizePath3-1] << "\n";
      map.print();
    } 
  }
  if(crossing4 && !done4){
     if(count4 <= sizePath4-2){
    count4++;
    map.setPos1(pathArray1[count1]);
    map.setPos2(pathArray2[count2]);
    map.setPos3(pathArray3[count3]);
    map.setPos4(pathArray4[count4]);
    currentPos4.write(pathArray4[count4]);
    nextPos4.write(pathArray4[count4+1]);
       cout << "@" << sc_time_stamp() << " robot4 crossed from position " << currentPos4.read() <<" to position " << nextPos4.read() << "\n";
      map.print();
    }else{
       const int a = pathArray4[sizePath4-1];
      map.setPos1(pathArray1[count1]);
    map.setPos2(pathArray2[count2]);
    map.setPos3(pathArray3[count3]);
      map.setPos4(pathArray4[count4]);
      currentPos4.write(a);
      nextPos4.write(a);
      done4 = true;
      cout << "@" << sc_time_stamp() << " robot4 rests at final position " << pathArray4[sizePath4-1] << "\n";
      map.print();
    }
  }
  }
}