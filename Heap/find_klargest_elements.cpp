
								//find kth largest elements from an given array
									// approach 1
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
int find_max(vector<int>&a)
{
	return a[0];
}
int main()
{
		vector<int>a = {5,20,100,3,10,1,2};
		built_maxheap(a);
		for(int i=0 ; i<3 ; i++)
		{
			cout << find_max(a) << " ";
			delete_max(a);
		}
		cout << endl;
		return 0;
}