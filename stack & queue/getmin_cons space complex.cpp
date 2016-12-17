
						// get min in constant time and space complexity i.e O(1)
							// here it is necessary to understand that 2 is necessary to multiply

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
	int min;
	stack<int>s;
public:
	void spush(int x)
	{
			if(s.empty())
			{
				min = x;
				s.push(x);
				return;
			}
			if(x < min)
			{
				s.push(2*x - min);
				min = x;
			}
			else
				s.push(x);
	}
	void spop()
	{
		if(!s.empty())
		{
			int t = s.top();
			//cout << "t ne val" << t << endl;
			s.pop();
			//cout << "topmost element removeed is ";
			if(t < min)
			{
		//		cout << min << endl;
				min = 2*min - t;
			}
		}
	}
	int get_min()
	{
		return min;
	}
};
int main()
{
	sta s;
	s.spush(7);
	s.spush(4);
	s.spush(5);
	s.spush(2);
	s.spush(-1);
	s.spush(6);
	s.spush(3);
	s.spush(-2);
	s.spush(-9);
	s.spop();
	cout << s.get_min() << endl;
	return 0;
}