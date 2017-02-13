					// longest increasing subsequence
					// using dynamic programming ... time complexity ->0(n^2);

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << " ";
	cout << endl;
}
void print_lis(vector<int>a , int max,vector<int>b)
{
	vector<int>fin;
	int temp = max;
	for(int i=b.size()-1 ; i>=0 ; i--)
	{
		if(b[i] == temp)
		{	
			fin.push_back(a[i]);
			temp--;
		}
	}
	reverse(fin.begin(),fin.end());
	print(fin);
}
int LCS(vector<int>a)
{
	vector<int>lcs(a.size(),1);
	for(int i=1 ;i<a.size() ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(a[i] > a[j] && lcs[i] < lcs[j] + 1)
			{
				lcs[i] = lcs[i] + 1;
			}
		}
	}
	auto iter = max_element(lcs.begin(),lcs.end());
	print_lis(a,*iter,lcs);
	return *iter;
}

int main()
{
	vector<int>a = {10, 22, 9, 33, 21, 50, 41, 60};
	cout << LCS(a) << endl;
	return 0;
}