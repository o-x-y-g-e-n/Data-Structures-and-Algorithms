
								//to check the paranthesis {{}} etc

#include <iostream>
#include <string>
#include <functional>
#include <valarray>
#include <vector>
#include <stack>
using namespace std;
bool check(char c , stack<char>&s)
{
	if(c == ')')
	{
		if(s.top() == '(')
			return true;
		else
			return false;
	}
	if(c == '}')
	{
		if(s.top() == '{')
			return true;
		else
			return false;
	}
	if(c == ']')
	{
		if(s.top() == '[')
			return true;
		else
			return false;
	}
}
bool check_paranthesis(string str)
{

			//to check balancing of symbols....{{}}
			stack<char> s;		
			auto iter = str.begin();
			while(iter != str.end())
			{
				auto c = *iter;
				if( (c>='a' && c<='z') || (c>='A' && c<='Z'))
					{}
				else if(c == '(' || c == '{' || c == '[')
					s.push(c);
				else if(c == '}' || c == ')' || c == ']')
				{
					if(s.empty())
						return false;
					if(check(c,s))
						s.pop();
					else
						return false;
				}
				iter++;
			}
			if(s.empty())
				return true;
			else
				return false;
}
int main()
{
	string s="((())){()}";
	if(check_paranthesis(s))
		cout << "matches" << endl;
	else
		cout << "doesnt match" << endl;
	return 0;
}