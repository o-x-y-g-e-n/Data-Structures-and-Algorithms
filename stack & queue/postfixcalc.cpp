
				//calculation of postfix equation

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
int calc(string str)
{
	stack<int>s;
	for(int i=0 ; i<str.size() ; i++)
	{
		if(isdigit(str[i]))
		{
				s.push(str[i] - '0');
		}
		else
		{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int sum=0;
			switch(str[i])
			{
				case '+':
				{
					sum = plus<int>()(b,a);
					break;
				}
				case '-':
				{
					sum = minus<int>()(b,a);
					break;
				}
				case '*':
				{
					sum = multiplies<int>()(a,b);
					break;
				}
				case '/':
				{
					sum = divides<int>()(b,a);
					break;
				}
			}//switch over
			s.push(sum);
		}	//else over
	}//for loop over
	return s.top();
}	
int main()
{
	string str = "123*+5-";
	cout << calc(str);
	return 0;
}