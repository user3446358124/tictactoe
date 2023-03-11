#include "Class_type.h"

 using namespace std;
int main()
{
	hello();

	int* map = new int[9] {};//0是空格，1是我方，2是敌方

	bool success=opeartor(map);

	char ch;

	do
	{ 
	nest(success);
	cout << endl<<"'q' to quit";
	cin >> ch;
	cout << endl;
	} while (ch != 'q');
}