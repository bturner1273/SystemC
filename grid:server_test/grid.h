#include <systemc.h>

struct Coordinate
{
  int x;
  int y;
};

//this is gonna go into server
struct nodeCol
{
  int index;	//node number
  int gridNum;	//which grid number it resides on
  int order[];	//index number of order going through
  
};

class grid
{
  public:
  	int pos1, pos2, pos3, pos4;
  	int mainGrid[8][10];
  	void makeGrid();
  	void setPos1(int pos);
 	void setPos2(int pos);
  	void setPos3(int pos);
  	void setPos4(int pos);
  	void setGridNum(Coordinate coor,int num);
  	void print(); //prints out the grid
  	void printCoor(Coordinate p);//prints out coordinate
  	//void nodeCol();	//finds order for the node collision cases, nevermind this 							is server
  	Coordinate findNext(Coordinate coor,int nextNum);
  	//equals function
  	
  
};