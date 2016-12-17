										//to convert infix to postfix using stack
							//without paranthesis....
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
	map<char,int> prior;
	prior.insert(make_pair<char,int>('/',4));
	prior.insert(make_pair<char,int>('*',3));
	prior.insert(make_pair<char,int>('+',2));
	prior.insert(make_pair<char,int>('-',1));
	if(prior[s1] >= prior[s2])
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
string f1(vector<char>str)
{
			//consider it without paranthesis
			vector<char>fin;
			stack<char>s;
			for(int i=0 ; i<str.size() ; i++)
			{
				auto c = str[i];
				if(isdigit(c) || isalpha(c))
					{fin.push_back(c);}
				else
				{
					while(!s.empty() && priority(s.top(),c))
					{
								fin.push_back(s.top());
								s.pop();
					}
					s.push(c);	
				}
			}
			while(!s.empty())
			{
				fin.push_back(s.top());
				s.pop();
			}	
			stringstream ss;
			for(int i=0 ; i<fin.size() ; i++)
			{
				ss << fin[i] ;
			}
			return ss.str();
}
int main()
{
		string s1 ="a+b*c-d";
		vector<char> s;
		for(int i=0 ; i<s1.size() ; i++)
			s.push_back(s1[i]);
		string fin = f1(s);
		cout << fin << endl;
		return 0;
}