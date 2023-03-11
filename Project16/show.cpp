#include "Class_type.h"

using namespace std;

void show(int* map)//0是空格，1是我方，2是敌方
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\t" << map[i * 3 ] << "|" << map[i * 3 + 1] << "|" << map[i * 3 + 2] << endl;
		if(i!=2)
		cout << "\t- - -"<<endl;
	}
}