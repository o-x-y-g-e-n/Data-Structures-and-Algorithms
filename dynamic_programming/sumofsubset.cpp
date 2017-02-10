
							// sum of subset problem .... bro !! but it yelled' ''' I AM DYNAMO '' ' '' ;
									// time complexity ==> min(2^n , n*w);

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
void print_arr(vector<int>a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << " ";
	cout << endl;
}
int function(int W , vector<int>val, int n)
{	
	bool arr[n+1][W+1];
	for(int i=0 ; i<=n ; i++)
	{
		arr[i][0] = true;
	}
	for(int i=1 ; i<=W ; i++)
	{	
		arr[0][i] = false;
	}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=W ; j++)
		{
			
			if(j >= val[i-1] &&  ((arr[i-1][j-val[i-1]] || arr[i-1][j])))
			{
				arr[i][j] = arr[i-1][j-val[i-1]] || arr[i-1][j];
			}
			else
			{
				arr[i][j] = arr[i-1][j];
			}

		}
	}
		// to find the items that are included //

	vector<int>fin;
	int x = n;
	int y = W;
	while(x > 0 && y > 0)
	{
		if(arr[x][y] != arr[x-1][y])
		{
			fin.push_back(x);
			x = x-1; y = W-val[x];
		}
		else
			x = x-1; 
	}
	print_arr(fin);
	return arr[n][W];
}
int main()
{
	int a; 
	vector<int>val = {6,3,2,1};
	int W = 5;
	 if(function(W,val,val.size()))
	 {
	 	cout << "it is possible" << endl;
	 }
	 else
	 	cout << "no such subsets found" << endl;
	return 0;
}