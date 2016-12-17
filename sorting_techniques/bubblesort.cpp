
								//>>BUBBLE SORT<<
					/*
						time complexity
						worst case --> O(n^2)
						best case (improved i.e code below) --> O(n) (sorted input)
						average case (basic version) --> O(n^2)
						space complexity --> O(1)
					*/

#include <iostream>
#include <string>
#include <valarray>
#include <iomanip>
#include <vector>
using namespace std;
void print(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << " ";
	cout << endl;
}a
int main()
{
	vector<int> a ={2,3,54,6,4,2,1,3,4,6,7};
	int swapped = 1;
	for(int i=0 ; i<a.size() && swapped; i++)
	{
		swapped = 0;
		for(int j=0 ; j<a.size()-i -1 ; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped  = 1;
			}
		}
	}
	print(a);
	return 0;
}