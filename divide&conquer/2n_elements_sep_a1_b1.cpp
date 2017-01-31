
					//given an array of size 2n a(1)a(2)a(3)a(4)b(1)b(2)b(3)b(4) seperate in a way a1b1a2b2a3b3a4b4..
					// time complexity --> 0(N) and space complexity --> 0(N)

#include <iostream>
#include <vector>	
#include <cmath>
#include <algorithm>
using namespace std;

void swap(int &a , int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void prints(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void function(vector<int>&a,int b_count,vector<int>&fin)
{
	
	int x = b_count;
	for(int i=0  ;i<x; i++)
	{
		fin.push_back(a[i]);
		fin.push_back(a[i+x]);
	}
}
int main()
{
	vector<int>fin; // this is the problem here.. now suppose we dont want to use an extra space.. see the next code..
	vector<int>a = {1,2,3,4,5,6,7,8};
	function(a,a.size()/2,fin);
	prints(fin);
	return 0;
}