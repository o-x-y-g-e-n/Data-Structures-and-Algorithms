
								// reverse the words in given string 												
									// time complexity --> O(n)
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int main()
{		
	string s1;
	getline(cin,s1);
	queue<int> q;
	q.push(0);
	int space=0;
	for(int i=0 ; i<s1.size() ;)
	{
		
		if(space == 0 && s1[i] == ' ')
		{
			reverse(s1.begin() + space , s1.begin() + i);
			space = i;	
		}
		if(s1[i] == ' ')
		{
			reverse(s1.begin() + space +1, s1.begin() + i);
			space = i;
			
		}
		else if(i ==s1.size() -1)
		{
			reverse(s1.begin()+space+1 , s1.end());
		}
		i++;
	}
	reverse(s1.begin(), s1.end());
	cout << s1 << endl;
	return 0;
}