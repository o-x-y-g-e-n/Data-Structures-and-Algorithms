
				// find missing no in the given arithmetic series..
				// using binary search
				// time complexity --> 0(logn)



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int bin_search_ap(vector<int>a)
{
	int low = 0 ;
	int high = a.size() -1;
	int first = a[0];
	int last = a[a.size()-1];
	while(low <= high)
	{
		int mid = (low + high)/2;
		int diff = (last-first)/a.size();  // can be used to find the diff when one no is missing in the AP.
		int val = first + (mid)*diff;
		if(val == a[mid])
		{
			low = mid+1;
		}
		else if(val != a[mid])
		{
			if(mid != low)
			{
				high = mid-1;
			}
			else
				return val;
		}

	}
}
int main()
{
	vector<int>a = {-2,0,2,4,6,8,10,12,14,16,20};
	cout << bin_search_ap(a) << endl;
	return 0;
}