

						// to find the next max element of each element in the array.
						// space complexity O(n)    // time complexity O(1)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>
#include <functional>
using namespace std;

void print(int *a,int l)
{
	for(int i=0 ; i<l ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void find(int *vec,int *fin,int l)
{
		int y;
		stack<int>s;
		s.push(0);
		for(int i=1 ; i<l ; i++)
		{
			while(!s.empty() && vec[s.top()] < vec[i])
			{
				fin[s.top()] = vec[i];
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty())
		{
			fin[s.top()] = -1;
			s.pop();
		}
}

int main()
{
	int temp[6] = {10,20,1,5,500,60};
	int fin[6];
	find(temp,fin,6);
	print(fin,6);
	return 0;
}