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
using namespace std;
bool priority(char s1  , char s2)
{
			//priority of s1 is greater than s2 --> return TRUE
	map<char,int> prior;
	prior.insert(make_pair<char,int>('/',4));
	prior.insert(make_pair<char,int>('*',3));
	prior.insert(make_pair<char,int>('+',2));
	prior.insert(make_pair<char,int>('-',1));
	if(prior[s1] > prior[s2])
		return true;
	else
		return false;

}
bool is_openparanthesis(char c)
{
	if(c == '(' || c == '{' || c == '[')
		return true;
	else
		return false;
}
bool is_closedparanthesis(char c)
{
	if(c == ')' || c == ']' || c == '}')
		return true;
	else
		return false;
}
void print(vector<char> a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << " ";
	cout << endl;
}
string change(vector<char>str)
{
	stack<char>s;
	vector<char>fin;
	
	for(int i=0 ; i<str.size() ; i++)
	{
		if(isalpha(str[i]))
		{
				fin.push_back(str[i]);

		}
		else if(is_openparanthesis(str[i]))
		{
			s.push(str[i]);
		}
		else if(is_closedparanthesis(str[i]))
		{
			while(!s.empty() && !is_openparanthesis(s.top()))
			{
				fin.push_back(s.top());
				s.pop();
			}
				s.pop();
		}
		else // it is an operator
		{
				
				while(!s.empty() &&  priority(s.top(),str[i]))
				{
						fin.push_back(s.top());
						s.pop();
				}
				s.push(str[i]);
		}
		//print(fin);
	}
	while(!s.empty())
	{
		fin.push_back(s.top());
		s.pop();
	}
	stringstream ss;
	for(int i=0 ; i<fin.size() ; i++)
		ss << fin[i] ;
	return ss.str();
}
int main()
{
		vector<char>str;
		string s = "(A+B)*C-(D-E)*(F+G)";
		for(int i=0 ; i<s.size() ; i++)
			str.push_back(s[i]);
		cout << change(str) << endl;
		return 0;
}