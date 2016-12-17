   

							//Quick-sort 
/*
			worst case time complexity --> O(n^2)
			best case and avg. case time complexity --> O(nlogn)
			worst case space complexity --> O(1)

			--> to avoid worst-case use ramdomized quick sort 
*/
	#include <iostream>
	#include <vector>
	#include <cmath>
	#include <algorithm>
	using namespace std;
	void swap_val(vector<int>&a,int c ,int b)
	{
		int temp = a[c];
		a[c] = a[b];
		a[b] = temp;
	}
	int partition(vector<int>&a,int low,int high)
	{
		int left,right,pivot_item=a[low];
		left = low;
		right = high;
		while(left < right)
		{
			while(a[left] <= pivot_item)
					left++;
			while(a[right] > pivot_item)
					right--;
			if(left < right)
				swap_val(a,left,right);
		}
		a[low] = a[right];
		a[right] = pivot_item;
		return right;
	}
	
	void print(vector<int> a)
	{
		for(int i=0 ; i<a.size() ; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	void quick_sort(vector<int>&a , int low ,int high)
	{
		int pivot;
		if(high > low)
		{
			pivot = partition(a,low,high);
			quick_sort(a,low,pivot-1);
			quick_sort(a,pivot+1,high);
		}
	}
	
	
	int main()
	{
			vector<int> a ={2,9,4,3,1};
			int size = a.size()-1;
			quick_sort(a,0,size);
			print(a);
			return 0;
	}


	/*
			properties of quick sort
			1) divide and conquer 
			2) recursive
			3) not a stable sorting algo
			
	*/