
									//min heapify the given array..
									// time complexity of max_heapify() function is 0(logn) and total time complexity of built heap is 0(n)
									// space complexity is 0(logn) bcs of recursion

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void print(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void min_heapify(vector<int>&a,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int smallest=i;
	if(l<a.size() && a[l] < a[i])
	{
		smallest = l;
	}
	else
		smallest = i;
	if(r < a.size() && a[r] < a[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(&a[i],&a[smallest]);
		min_heapify(a,smallest);	
	}

}
void built_minheap(vector<int>&a)
{
	for(int i=(a.size()/2)-1 ; i>=0 ; i--)
	{
		min_heapify(a,i);
	}
}
int main()
{
	vector<int>a={211,21,20,26,50,5};
	vector<int>b;
	for(int i=0 ;i<3 ;i++)
	{
		b.push_back(a[i]);
	}
	built_minheap(b);
	for(int i=b.size() ; i<a.size() ; i++)
	{
		if(b[0] < a[i])
		{	
			swap(&b[0],&a[i]);
			min_heapify(b,0);
		}
	}
	print(b);
	return 0;
}