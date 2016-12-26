
			//find maximum ocuring character in given string ---
				// time complexity -> O(n)

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int temp[256]={0};
	string s;
	cin >> s;
	char maxc = ' ';
	int maxi = -1;
	for(int i=0 ; i<s.size(); i++)
	{
		temp[s[i]]++;
	}
	for(int i=0 ; i<256; i++)
	{
		if(temp[i] > maxi)
			maxi = temp[i];
	}
	cout << s[maxi] << endl;
	return 0;
}

