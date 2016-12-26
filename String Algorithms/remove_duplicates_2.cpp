
				// to remove  duplicates from given string
					// time complexity --> O(n)
				// space complexity --> O(1)

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
	cin >> s;
	int hash[256] = {0};
	int i = 0;
	int curr_index = 0  , fin_index = 0;
	char temp;
	while(s[curr_index])
	{
		temp = s[curr_index];
		if(hash[temp] == 0)
		{
			hash[temp]  = 1;
			s[fin_index++] = s[curr_index];
		}
		curr_index++;
	}
	s[fin_index] = '0';
	for(int i=0 ; i<s.size() ; i++)
	{
		if(s[i] == '0')
			break;
		cout << s[i];
	}
	cout << endl;
	return 0;
}