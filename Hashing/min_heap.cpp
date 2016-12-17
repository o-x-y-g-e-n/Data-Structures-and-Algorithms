
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
	if(l<=a.size() && a[l] < a[i])
	{
		smallest = l;
	}
	else
		smallest = i;
	if(r <= a.size() && a[r] < a[smallest])
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
//delete max element 
void delete_min(vector<int>&a)
{
	if(a.size() < 1)
	{
		cout << "heap underflow";
		return;
	}
	int temp = a[a.size() -1];
	a.erase(remove(a.begin(), a.end(), temp), a.end());
	a[0] = temp;
	min_heapify(a,0);
}
// increase an key by given val
void increase_key(vector<int>&a,int i , int key)
{
	if(key < a[i])
		return;
	a[i] = key;
	while(i>=0 && a[i/2] > a[i])
	{	
		swap(a[i],a[i/2]);
		i = i/2;
	}
}
// decrease an key by given val
void decrease_key(vector<int>&a,int i , int key)
{
	if(key > a[i])
		return;
	a[i] = key;
	min_heapify(a,i);
}
void insert_element(vector<int>&a,int val)
{
	
	a.push_back(-999);
	increase_key(a,7,val);
}

int main()
{

	return 0;
}