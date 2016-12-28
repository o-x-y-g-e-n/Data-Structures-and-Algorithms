					// to check whether two strings are anagrams of each other or not
					// time complexity --> O(n) + O(n) = O(n)



#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iterator>
using namespace std;
void print(int *arr,int size)
{
	for(int i=0 ; i<size ; i++)
		cout << arr[i] << " ";
	cout << endl;
}
bool check(string s1 ,string s2)
{
	int count=0;
	vector<int>hash(256,0);
	if(s1.size() != s2.size())
		return false;
	for(int i=0 ; i<s1.size() ; i++)
	{
		hash[s1[i]]++;
	}
	for(int i=0 ; i<s2.size(); i++)
	{
		hash[s2[i]]--;
	}
	vector<int>::iterator iter = find_if(hash.begin(),hash.end(),[](int x){return x>0;});
	if(iter != hash.end())
		return false;
	else
		return true;
	
}
int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	if(check(s1,s2))
		cout << "both are anagrams of each other" << endl;
	else
		cout << "they are not " << endl;
	return 0;
}