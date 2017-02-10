
							// 0/1 knapsack problem .... bro !! but it yelled' ''' I AM DYNAMO '' ' '' ;
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
int knapsack(int W , vector<int>weight , vector<int>profit,int n)
{	
	int arr[n+1][W+1];
	for(int i=0 ; i<=n ; i++)
	{
		arr[i][0] = 0;
	}
	for(int i=0 ; i<=W ; i++)
	{	
		arr[0][i] = 0;
	}
	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=W ; j++)
		{
			if((weight[i-1] <= j) && ((arr[i-1][j-weight[i-1]]+profit[i-1])) > arr[i-1][j])
			{
				arr[i][j] = arr[i-1][j-weight[i-1]] + profit[i-1];
			}
			else
				arr[i][j] = arr[i-1][j];
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
			x = x-1; y = W-weight[x];
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
	vector<int>weight = {2,3,4,5};
	vector<int>profit = {3,4,5,6};
	int W = 5;
	cout << knapsack(W,weight , profit,weight.size()) << endl;
	return 0;
}