#include<iostream>
#define NUMBER 4
#define INFINITE 200000000
using namespace std;
 
int table[NUMBER][NUMBER] = {
	 {0,5,7,INFINITE}
	,{4,0,12,13}
	,{6,INFINITE,0,20}
	,{INFINITE,9,8,0}
};
 
 
void FloydFunction()
{
	for (int k = 0; k < NUMBER; k++) {
 
		for (int i = 0; i < NUMBER; i++)
		{
			for (int j = 0; j < NUMBER; j++)
			{
 
				int temp = table[i][k] + table[k][j];
				if (temp < table[i][j])
					table[i][j] = temp;
 
			}
		}
	}
}
void printTable()
{
	for (int i = 0; i < NUMBER; i++)
	{
		for (int j = 0; j < NUMBER; j++)
		{
			cout << table[i][j]<<" ";
		}
		cout << endl;
	}
}
 
int main()
{
	FloydFunction();
	printTable();
 
	return 0;
}