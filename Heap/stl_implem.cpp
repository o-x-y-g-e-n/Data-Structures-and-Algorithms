
								// heap implementation using c++ stl.....
								
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void print(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	vector<int>a = {13,45,31,24,53};
	// to make the heap
	make_heap(a.begin(),a.end());	
	// to retreive the max element
	cout << a.front() << endl;
	// to enter a element in the heap
	a.push_back(200);
	push_heap(a.begin(),a.end());	
	// to sort the heap
	sort_heap(a.begin(),a.end());
	/*
			FOR MIN HEAP -->
			1) make_heap(a.begin(),a.end(),[](int x ,int y){return x>y;});
			2) make_heap(a.begin(),a.end(),[](int x ,int y){return x>y;});
			3) and to sort ascending or descending use the same thing...
	*/
	return 0;
}
