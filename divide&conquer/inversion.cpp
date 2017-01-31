   
						// inversion problem 
						// time complexity same as the merge sort --> 0(nlogn)
		
	#include <iostream>
	#include <vector>
	#include <cmath>
	#include <algorithm>
	using namespace std;
	int COUNT= 0;
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
			if(l[i] <= r[j])
			{
				a[k] = l[i];
				k++;
				i++;
			}
			else
			{
				if(l.size() == 1 && r.size() == 1)
					COUNT = COUNT + 1;
				else
					COUNT = COUNT + (l.size()-i);
				cout << l[i] << " " << r[j] << " "<< COUNT << endl;
				a[k] = 	r[j];
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
		vector<int>().swap(l);			 
		vector<int>().swap(r);			
	}
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
			vector<int> a ={7,5,3,2,1,6,8,14,2};
			merge_sort(a);
			cout << COUNT << endl;
			return 0;
	}


