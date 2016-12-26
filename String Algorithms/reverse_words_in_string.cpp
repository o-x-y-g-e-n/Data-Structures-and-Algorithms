
								// reverse the words in given string 												
							
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{		
	string s1;
	getline(cin,s1);
	for(int i=0 ; i<s1.size() ; i++)
	{
		if(s1[i] == ' ')
		{
			reverse(s1.begin()+i,s1.begin());
		}
	}
	cout << s1 << endl;
	return 0;
}