
					// check whether two strings are rotation of each other or not
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
	string s1,s2,conc;
	cin >> s1;
	cin >> s2;
	if(s1.size() != s2.size())
		return -1;
	conc = s1 + s1;
	auto fi = conc.find(s2);
	if(fi != -1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;	
}