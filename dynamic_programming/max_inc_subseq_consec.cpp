//longest consecutive subseqecne with consecutive integers in list
// time complexixty --> 0(N) (almost) (can be greater)
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
using namespace std;
int main()
{
	vector<int>arr= {16,2,3,4,1,10,11,17,18,19,15,13,12,14};
	int ans = 0;
	unordered_set<int>S;
	for(int i=0 ; i<arr.size() ;i++)
		S.insert(arr[i]);
	for(int i=0 ; i<S.size() ;i++)
	{
		if(S.find(arr[i]-1) == S.end())
		{
			int j = arr[i];
			while(S.find(j) != S.end())
				j++;
			ans = max(ans,j-arr[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
