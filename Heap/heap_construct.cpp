
									//max heapify the given array..
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
void max_heapify(vector<int>&a,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest=i;
	if(l<a.size() && a[l] > a[i])
	{
		largest = l;
	}
	else
		largest = i;
	if(r < a.size() && a[r] > a[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(&a[i],&a[largest]);
		max_heapify(a,largest);	
	}

}
void built_maxheap(vector<int>&a)
{
	for(int i=(a.size()/2)-1 ; i>=0 ; i--)
	{
		max_heapify(a,i);
	}
}
//delete max element 
void delete_max(vector<int>&a)
{
	if(a.size() < 1)
	{
		cout << "heap underflow";
		return;
	}
	int temp = a[a.size() -1];
	a.erase(remove(a.begin(), a.end(), temp), a.end());
	a[0] = temp;
	max_heapify(a,0);
}
// increase an key by given val
void increase_key(vector<int>&a,int i , int key)
{
	if(key < a[i])
		return;
	a[i] = key;
	while(i>=0 && a[i/2] < a[i])
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
	max_heapify(a,i);
}
void insert_element(vector<int>&a,int val)
{
	
	a.push_back(-999);
	increase_key(a,7,val);
}
int main()
{
	vector<int>a = {1,3,10,5,20,100,50};
	built_maxheap(a);
	print(a);
	insert_element(a,21);
	print(a);
	return 0;
}