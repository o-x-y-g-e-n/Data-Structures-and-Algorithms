
			// to find an element in the array for which a[i] = i for non repeated no .. sorted array;
				// use binary search .. time complexity --> 0(logN)


#include <iostream>
#include <vector>	
#include <cmath>
#include <algorithm>
using namespace std;
int check(vector<int>a)
{
	int low = 0;
	int high = a.size()-1;
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(mid == a[mid])
			return mid;
		else if(a[mid] < mid)
		{
			low = mid + 1;
		}
		else if(mid < a[mid])
		{
			high = mid - 1;
		}
	}
	return -1;	
}
int main()
{
	vector<int>a = {-10, -5, 3, 4, 7, 9};
	cout << check(a) << endl;
	return 0;
}