
					// to search an element in the circular sorted array
						// time complexity --> 0(logn)



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
using namespace std;
int bin_search(vector<int>a , int start , int end , int data)
{
	int low = start;
	int high = end;
	if(low > high)
		return -1;
	int mid = (low + high)/2;
	if(a[mid] == data)
	{
		return mid;
	}
	else if(a[mid+1] <= a[high])
	{
		if(data >= a[mid+1] && data <= a[high])
			return bin_search(a,mid+1,high,data);
		return bin_search(a,low,mid-1,data);
	}
	else if(a[low] <= a[mid-1])
	{
		if(data >= a[low] && data <= a[mid])
			return bin_search(a,low,mid-1,data);
		return bin_search(a,mid+1,high,data);
	}

}

int main()
{	
	vector<int>a = {7,8,9,10,1,2,3,4,5};
	cout << bin_search(a,0,a.size()-1,5) << endl;
	return 0;
}