#include "Class_type.h"

using namespace std;

int success_rate(int* map,int a)
{
	int rec = 0;
	int waring = 0;

	int record[9] = { 0 };//�����һ��2������������һ��Ϊ1��������λ��Ϊ11������ֻҪ��һ��1����ֱ�����㣻 			
	// ���ÿһ��   			
	for (int i = 0; i < 3; i++)
	{
		if (map[i * 3 + 0] == a || map[i * 3 + 1] == a || map[i * 3 + 2] == a)
			;
		else
		{ 
			int b = 1;
			for (int j = 0; j < 3; j++)
			{ 
				if (map[i * 3 + j] == 2)
				{ 
					for (int k = 0; k < 3; k++,b+=10)
						record[i * 3 + k] += b;
				}
			}
		}
	}
	// ���ÿһ��   			
	for (int i = 0; i < 3; i++)
	{
		if (map[i] == a || map[i + 3] == a || map[i + 6] == a)
			;
		else
		{
			int b = 1;
			for (int j = 0; j < 3; j++)
			{
				if (map[i + j * 3] == 2)
				{
					for (int k = 0; k < 3; k++,b+=10)
						record[i  + k * 3] += b;
				}
			}
		}
	}
	// ���Խ���   			
	if (map[0] == a || map[4] == a || map[8] == a)
	{
		;
	}
	else
	{
		int b = 1;
		for (int j = 0; j < 3; j++)
		{
			if (map[0 + j * 4] == 2)
			{ 
				for (int k = 0; k < 3; k++, b += 10)
					record[0 + k * 4] += b;
			}
		}
	}

	if (map[2] == a || map[4] == a || map[6] == a)
	{
		;
	}
	else
	{
		int b = 1;
		for (int j = 0; j < 3; j++)
		{
			if (map[2 + j * 2] == 2)
			{ 
				for (int k = 0; k < 3; k++, b += 10)
					record[2 + k * 2] += b;
			}
		}
	}

	//ѡ��
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (record[i] > max && map[i] == 0)
		{
			max = record[i];
			rec = i;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (record[i] == max && map[i] == 0 && rand() % 2)
		{
			rec = i;
		}
	}

		return rec;
}