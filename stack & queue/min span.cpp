
					// finding span with min time complexity...i.e O(n);

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
void cal_span(int arr[],int length , int fin[])
{
	stack<int>s;
	s.push(0);
	fin[0] = 1;
	for(int i=1 ; i<length ; i++)
	{
		while(!s.empty() && arr[s.top()] < arr[i])
		{
			s.pop();
		}
		fin[i] = (s.empty()) ? (i+1) : (i-s.top());
		s.push(i);
	}
}
int main()
{
	int arr[ ]={10,4,5,90,120,80};
	int fin[6]={0};
	cal_span(arr,6,fin);
	for(int i=0 ; i<6 ;i++)
		cout << fin[i] << " ";
	cout << endl;
	return 0; 
}