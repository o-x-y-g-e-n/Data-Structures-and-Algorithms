	//largest sum contigious subarray
	// time complexity --> 0(N)
	// kadane's alggorithm
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int max_so_far=0, max_current=0,index;
	vector<int>vec={-2,-3,4,-1,-2,1,5,-3};
	for(int i=0 ; i<vec.size() ; i++)
	{
		max_current = max_current + vec[i];
		if(max_current < 0)
			max_current=0;
		else if(max_so_far < max_current)
		{
			max_so_far = max_current;
			index = i;
		}
	}
	int sum = 0;
	vector<int>ans;
	for(int i=index ; i>=0 ; i--)
	{	
		if(sum != max_so_far)
		{
			sum = sum + vec[i];
			ans.push_back(vec[i]);
		}
	}
	for(int i=0 ; i<ans.size() ;i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
