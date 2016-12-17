   

							//Heap sort 
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
	
	int main()
	{
			vector<int> a ={96,1,2,3,5,7,9,6,4,3,4,5,7,6,2,1,34};
			merge_sort(a);
			print(a);
			return 0;
	}