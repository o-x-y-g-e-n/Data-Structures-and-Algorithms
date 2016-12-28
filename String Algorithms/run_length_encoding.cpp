

				// run length encoding
				// time complexity --> O(n)
			
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
void print(int *arr,int size)
{
	for(int i=0 ; i<size ; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	string str;
	cin >> str;
	vector<char>f_str;
	int count=0;
	for(int i=0 ; i<str.size() ; i++)
	{
		if(str[i] == str[i+1])
			count++;
		else
		{
			f_str.push_back(1+count + '0');
			count=0;
			f_str.push_back(str[i]);
		}
	}
	stringstream stm;
	for(int i=0 ; i<f_str.size() ; i++)
		stm << f_str[i];
	cout << stm.str() << endl;
	return 0;
}