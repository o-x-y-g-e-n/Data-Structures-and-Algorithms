

		// to count no of 1's in the series containing 1's after all 0's // 
				// time complexity --> binary search --> 0(logn) //

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int count(vector<int>a)
{
	int low = 0;
	int high = a.size()- 1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(a[mid]== 0)
		{
			low  = mid + 1;
		}
		else if(a[mid] == 1)
		{
			if(a[mid-1] == 1)
			{
				high = mid - 1;
			}
			else
				return mid;
		}
	}
}
int main()
{
	vector<int>a = {0,0,0,0,0,1,1,1,1,1};
	int c = count(a); // give me the breakpoint of 0 and 1
	int d = a.size() - c;  // to count total no of 1's
	cout << d << endl;
	return 0; 
}