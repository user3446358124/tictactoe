#include "Class_type.h"
using namespace std;

bool opeartor(int* map)  
{  	
	int time = 0;//第几次使用，用于主导defend主动选择中心位置

	int x, y;    	
	int i = 0;    	
	while (i < 9)//就是为了能循环进行  	
	{  		
		cout << "接下来是我方输出" << endl;  		
		if (cin >> x >> y)//我方输入   		
		{  			
			if (map[(x - 1) * 3 + y - 1] == 0)  				
				map[(x - 1) * 3 + y - 1] = 1;  			
			else  				
				continue;    			
			show(map);  		
		}  		
		else  		
		{  			
			cout << "错误!" << endl;  			
			cin.clear();  			
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  			
			continue;  		
		}  		
		if (!judge(map))  			
			return 1;    		
		
		cout << "接下来是对方输出" << endl;  	    
		
		defend(map,time++);  		
		
		show(map);  		
		
		if (!judge(map))  			
			return 1;  	
	}  
	return 0;
}