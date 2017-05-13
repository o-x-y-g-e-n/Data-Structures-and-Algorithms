 		// maximum increasing sum subsqeunce
		// time complexity --> 0(N^2)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int>vec={100,20,10,5,4,1};
	int max=0;
	vector<int>msis;
	for(int i=0 ; i<vec.size() ; i++)
		msis.push_back(vec[i]);
	for(int i=1 ; i<vec.size() ; i++)
	{
		for(int j=0 ; j<i ; j++)
		{
			if(vec[i] > vec[j] && msis[i] < msis[j] + vec[i])
				msis[i] = msis[j] + vec[i];
		}
	}
	for(int i=0 ; i<vec.size() ; i++)
	{
		if(max < msis[i])
			max = msis[i];
	}
	cout << max << endl;

}
