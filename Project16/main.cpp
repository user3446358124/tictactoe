#include "Class_type.h"

 using namespace std;
int main()
{
	hello();

	int* map = new int[9] {};//0�ǿո�1���ҷ���2�ǵз�

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