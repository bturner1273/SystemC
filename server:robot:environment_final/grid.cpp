#include <systemc.h>
#include <grid.h>

void grid::makeGrid()
{
  int ass=1;	//assign integer to each cell
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<10;j++)
    {
      if((i==1)&&(j>=1)&&(j<9))
      {
        mainGrid[i][j]=0;		//object
      }
      else if((i==2)&&(j>=1)&&(j<9))
      {
        mainGrid[i][j]=0;		//objects
      }
      else if(((i==4)&&(j>=1)&&(j<=3))||((i==4)&&(j>=5)&&(j<=8)))
      {
        mainGrid[i][j]=0;
      }
      else if(((i==5)&&(j>=1)&&(j<=3))||((i==5)&&(j>=5)&&(j<=8)))
      {
        mainGrid[i][j]=0;
      }
      else if(((i==6)&&(j>=1)&&(j<=3))||((i==6)&&(j>=5)&&(j<=8)))
      {
        mainGrid[i][j]=0;
      }
      else
      {
        mainGrid[i][j]=ass++;
      }
      
    }
  }   
}
void grid::setGridNum(Coordinate coor,int num)
{
  mainGrid[coor.x][coor.y]=num;
}

void grid::printPeople()
{
  cout << "Position Update:\n--------------------------------------------------------------------------\n";
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<10;j++)
    {
      if(((mainGrid[i][j] == pos1) || (mainGrid[i][j] == pos2) || (mainGrid[i][j] == pos3) || (mainGrid[i][j] == pos4)) && mainGrid[i][j] == posp1){
        cout << "[P]\t";
      }
      else if(((mainGrid[i][j] == pos1) || (mainGrid[i][j] == pos2) || (mainGrid[i][j] == pos3) || (mainGrid[i][j] == pos4))){
       cout <<"["<<mainGrid[i][j]<<"]\t";
      }
      else if((mainGrid[i][j] == posp1)){
       cout <<"P\t";
      }
     else{
      cout<<mainGrid[i][j]<<"\t";
      }
    }
    cout<<"\n";
  }
  cout << "--------------------------------------------------------------------------\n";
  return;
}
         
//prints grid
void grid::print()
{
  cout << "Position Update:\n--------------------------------------------------------------------------\n";
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<10;j++)
    {
      if(((mainGrid[i][j] == pos1) || (mainGrid[i][j] == pos2) || (mainGrid[i][j] == pos3) || (mainGrid[i][j] == pos4))){
       cout <<"["<<mainGrid[i][j]<<"]\t";
      }else{
      cout<<mainGrid[i][j]<<"\t";
      }
    }
    cout<<"\n";
  }
  cout << "--------------------------------------------------------------------------\n";
  return;
}

Coordinate grid::findNext(Coordinate coor,int nextNum)
{
  //takes in the current coordinate, and compares
  //the array with the nextNum val, till it matches
  //returns that coordinate value
  int x=coor.x;
  int y=coor.y;
  int i,j;
  for(i=0;i<8;i++)
  {
    for(j=0;j<10;j++)
    {
      //if it finds the num break out
      if(mainGrid[i][j]==nextNum)
      {
        break;
      }
    }
    //if you broke out break out again
    if(mainGrid[i][j]==nextNum)
    {
      break;
    }
  }
  //make new coordinate to return
  Coordinate n;
  n.x=i;
  n.y=j;
  
  //if we needed to output direction we could compare
  //the previous value to the next value, with 4 cases
  //you could determine a direction as string
  return n;
}
void grid::printCoor(Coordinate p)
{
  cout<<"("<<p.x<<","<<p.y<<")";
}
void grid:: setPosp1(int pos){
 posp1 = pos;
}
void grid:: setPos1(int pos){
 pos1 = pos;
}
void grid:: setPos2(int pos){
 pos2 = pos;
}
void grid:: setPos3(int pos){
 pos3 = pos;
}
void grid:: setPos4(int pos){
 pos4 = pos;
}