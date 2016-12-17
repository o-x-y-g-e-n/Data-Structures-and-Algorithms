   /*
			inplace sorting algoritm --> the algorithm with constant space complexity..
   */

							//Selection sort
/*
			worst case time complexity --> O(n^2)
			best case and avg. case time complexity --> O(n^2)
			worst case space complexity --> O(n)
*/
	#include <iostream>
	#include <valarray>
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

	void selection_sort(vector<int> &a)
	{
			int temp,min;
			for(int i=0 ; i<a.size() ; i++)
			{
				 min = i;
				for(int j=i+1 ; j<a.size() ; j++)
				{
					if(a[j] < a[min])
						min = j;
				}
				temp = a[i];
				a[i]= a[min];
				a[min] = temp;
			}
	}
	int main()
	{
			vector<int> a ={2,1,3,4,6,6,4,3,2,2,4,6,8,9,6,54,5,45,43,2,12};
			selection_sort(a);
			print(a);
			return 0;
	}