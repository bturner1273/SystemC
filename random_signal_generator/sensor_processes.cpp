#include <systemc.h>
#include <stdlib.h>
#include <time.h>
#include <sensor.h>
#include <stdio.h>
using namespace std;



void sensor :: generateSample(){
 	srand(time(NULL));
  while(1){
   	int a = (rand()%1024);
  	int b = (rand()%1024);
	x.write(a);	
 	y.write(b);
    wait(1);
  }
}
