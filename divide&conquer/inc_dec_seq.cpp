			// to find i where 0.. a[i] is increasing and a[i+1].. a[n] is decreasing sequence
			/// using similar function as binary search .. i.e time complexity --> 0(logn)


#include <iostream>
#include <vector>	
#include <cmath>
#include <algorithm>
using namespace std;
int function(vector<int>a)
{
	int low = 0;
	int high = a.size()-1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		int left = a[mid-1];
		int right = a[mid+1];
		if((left < a[mid])  && (a[mid] > right))
		{
			return a[mid];
		}
		else if(left < a[mid] && a[mid] < right)
		{
			low = mid + 1;
		}
		else if(left > a[mid] && a[mid] > right)
		{
			high = mid - 1;
		}
	}
	return -1;
}
int main()
{
	vector<int>a = {1,8,7,6,5,4,3};
	cout << function(a) << endl;
	return 0;
}