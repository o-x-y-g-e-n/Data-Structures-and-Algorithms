   

							//Merge sort 
/*
			worst case time complexity --> O(nlogn)
			best case and avg. case time complexity --> O(nlogn)
			worst case space complexity --> O(n) auxillary
*/
	#include <iostream>
	#include <vector>
	#include <cmath>
	#include <algorithm>
	using namespace std;
	void print(vector<int> a)
	{
		for(int i=0 ; i<a.size() ; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	void merge(vector<int> &a,vector<int>&l , vector<int> &r)
	{
		int i=0,j=0,k=0;
		while(i < l.size() && j<r.size())
		{
			if(l[i] < r[j])
			{
				a[k] = l[i];
				k++;
				i++;
			}
			else
			{
				a[k] = r[j];
				k++;
				j++;
			}
		}
		while(i < l.size())
		{
			a[k++] = l[i++];
		}
		while(j < r.size())
		{
			a[k++] = r[j++];
		}
		vector<int>().swap(l);			//to dealocate memory of the vector like free 
		vector<int>().swap(r);			// to dealocate memory of the vector like free
	}
			/*
				if u donot deallocate the space then the space complexity is O(nlogn) ...
				but if you dealocate then the space is O(n)
			*/
	void merge_sort(vector<int> &a)
	{
			vector<int> r;
			vector<int> l;
			if(a.size() < 2)
				return;
			int mid = a.size()/2;
			for(int i=0 ; i<mid  ;i++)
				l.push_back(a[i]);
			for(int i=mid ; i<a.size() ; i++)
				r.push_back(a[i]);
			merge_sort(l);
			merge_sort(r);
			merge(a,l,r);
	}
	int main()
	{
			vector<int> a ={96,1,2,3,5,7,9,6,4,3,4,5,7,6,2,1,34};
			merge_sort(a);
			print(a);
			return 0;
	}


	/*
		some properties of merge sort ....//

				--> divide and conquer
				--> recursive
				--> stable (order maintained)
				--> not In-Place algorithm i,e takes extra space of memory
	*/
