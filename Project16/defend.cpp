#include "Class_type.h"  

using namespace std;
void defend(int *map,int functiontime) 
{ 	
	int rec = 0;  	
	int a, b;

	a = success_rate(map, 1);
	b = success_rate(map, 2);

	if (!functiontime&&map[4]==0)
		rec = 4;
	else
		 a > b ? rec=a: rec=b;

	*(map + rec) = 2;
	return; 
}