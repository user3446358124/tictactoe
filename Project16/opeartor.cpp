#include "Class_type.h"
using namespace std;

bool opeartor(int* map)  
{  	
	int time = 0;//�ڼ���ʹ�ã���������defend����ѡ������λ��

	int x, y;    	
	int i = 0;    	
	while (i < 9)//����Ϊ����ѭ������  	
	{  		
		cout << "���������ҷ����" << endl;  		
		if (cin >> x >> y)//�ҷ�����   		
		{  			
			if (map[(x - 1) * 3 + y - 1] == 0)  				
				map[(x - 1) * 3 + y - 1] = 1;  			
			else  				
				continue;    			
			show(map);  		
		}  		
		else  		
		{  			
			cout << "����!" << endl;  			
			cin.clear();  			
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  			
			continue;  		
		}  		
		if (!judge(map))  			
			return 1;    		
		
		cout << "�������ǶԷ����" << endl;  	    
		
		defend(map,time++);  		
		
		show(map);  		
		
		if (!judge(map))  			
			return 1;  	
	}  
	return 0;
}