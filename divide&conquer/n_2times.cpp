
						// to check whether the no has occured more than n/2 times or not in an sorted array
							// time complexity of the algorithm is 0(logn) + 0(logn) = 0(logn)



#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
using namespace std;
// finding first occurence of the no
int bin_search_first_occ(vector<int> a ,int data)
{
	int low = 0;
	int high = a.size() - 1;
	int element=-1;
	while(low <= high)
	{
		int mid = (high+low)/2;
		if(a[mid] == data)
		{
			element = mid;
			high = mid - 1;	
		}
		else if(a[mid] < data)
		{
			low = mid + 1;
		}
		else if(data < a[mid])
		{
			high = mid - 1;
		}
	}
	return element;
}
// finding last occurence of the no
int bin_search_last_occur(vector<int> a ,int data)
{
	int low = 0;
	int high = a.size() - 1;
	int element=-1;
	while(low <= high)
	{
		int mid = (high+low)/2;
		if(a[mid] == data)
		{
			element = mid;
			low = mid + 1;	
		}
		else if(a[mid] < data)
		{
			low = mid + 1;
		}
		else if(data < a[mid])
		{
			high = mid - 1;
		}
	}
	return element;	
}
int main()
{
	vector<int>a = {1,2,3,3,3,3,4};
	int size = (a.size() /2);
	int x1 = bin_search_first_occ(a,a[size]);
	int x2 = bin_search_last_occur(a,a[size]);
	if((x2-x1) >= size)
	{
		cout << "yes it exists" << endl;
	}
	else
		cout << "no such element exists" << endl;
	return 0;
}