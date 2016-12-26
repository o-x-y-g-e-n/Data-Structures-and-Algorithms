
			//remove duplicates from a given string
	// time complexity --> O(n)

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
		string s;
		vector<char> b;
		cin >> s;
		int hash[256]={0};
		for(int i=0  ;i<s.size() ; i++)
		{
			if(hash[s[i]] == 0)
			{	
				hash[s[i]] = 1;
				b.push_back(s[i]);
			}
		}
		stringstream stm;
		for(int i=0 ; i<b.size() ; i++)
			stm << b[i] ;
		cout << stm.str() << endl;
		return 0;
}