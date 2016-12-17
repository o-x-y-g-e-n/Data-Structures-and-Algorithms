
					//queue using 1 stack using reverse function(to reverse stack)
					//here the reverse function is implemented using only push and pop operations wihout using any external memory.

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
void bottom_insert(int x,stack<int>&s)
{
		if(s.size() == 0)
		{
			s.push(x);
		}
		else
		{
			int a = s.top();
			s.pop();
			bottom_insert(x,s);
			s.push(a);
		}
}
void reverse(stack<int>&s)
{
	if(s.size() > 0)
	{
		int x = s.top();
		s.pop();
		reverse(s);
		bottom_insert(x,s);
	}
}
void print(stack<int>s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
int main()
{
		stack<int>s;
		s.push(1);
		s.push(2);
		s.push(3);
		reverse(s);
		print(s);
		return 0;
}