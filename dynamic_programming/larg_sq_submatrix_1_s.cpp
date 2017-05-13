			// largest sub-matrix with all 1's
			// time complexity --> 0(N^2)
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 4
using namespace std;
int main()
{
	int arr[SIZE][SIZE] = {{1,1,1,1},{0,0,1,1},{1,1,1,1},{0,1,1,1}};
	int ans[SIZE][SIZE];
	int max = 0;
	for(int i=0 ; i<SIZE ; i++)
	{
		ans[i][0] = arr[i][0];
		ans[0][i] = arr[0][i];	
	}
	for(int i=1 ; i<SIZE ; i++)
	{
		for(int j=1 ;j <SIZE ; j++)
		{
			if(arr[i][j] == 0)
				continue;
			int x = min(ans[i-1][j-1] , ans[i-1][j]);
			int y = min(x,ans[i][j-1]);
			ans[i][j] = y + 1;
			if(ans[i][j] > max)
			max = ans[i][j];
		}
	}
	cout << max << endl;
}
