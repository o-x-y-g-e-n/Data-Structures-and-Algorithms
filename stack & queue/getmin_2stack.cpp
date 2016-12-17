

						//get minimum in O(1) time compelexity using 2 stack 
							/// this is the improved version i.e take a little less than O(n) space compelexity in best case but O(n) in worst case

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
class sta
{
private:
	stack<int>s1;
	stack<int>s2;
public:
	void spush(int no)
	{
		if(s1.empty())
		{
			s1.push(no);
			s2.push(no);
		}
		else
		{
			s1.push(no);
			if(no <= s2.top())
			{
				s2.push(no);
			}
		}
	}
	void spop()
	{
		if(s1.top() != s2.top())
		{
			s1.pop();
		}
		else
		{
			s1.pop();
			s2.pop();
		}
	}
	int get_min()
	{
		return s2.top();
	}
	void print()
	{
		stack<int>s1c = s1;
		stack<int>s2c = s2;
		cout << "the value of s1 stack ";
		while(!s1c.empty())
		{
			cout << s1c.top() << " ";
			s1c.pop();
		}
		cout << endl;
		cout << "value of second stack ";
		while(!s2c.empty())
		{
			cout << s2c.top() << " ";
			s2c.pop();
		}
	}
};
int main()
{
		sta s;
		s.spush(-1);
		s.spush(4);
		s.spush(-1);
		s.spush(4);
		s.print();
		return 0;
}