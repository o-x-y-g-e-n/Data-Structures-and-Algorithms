
		
					// finding longest common subsequence //
					// time complexity --> 0(n x m)	//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
void print_array(vector<char>a)
{
	for(int i=0 ; i<a.size() ; i++)
		cout << a[i] << "-";
	cout << endl;
}
int LCS(vector<char>a,vector<char>b)
{
	int arr[a.size()+1][b.size()+1];
	for(int i=0 ; i<=a.size() ;i++)
	{
		arr[i][0] = 0;
	}
	for(int i=0 ; i<=b.size() ; i++)
	{
		arr[0][i] = 0;
	}
	for(int i=1 ; i<=a.size() ; i++)
	{
		for(int j=1 ; j<=b.size() ; j++)
		{
			if(a[i-1] == b[j-1])
			{
				arr[i][j] = arr[i-1][j-1] + 1 ; 
			}
			else
				arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
		}
	}
	

		// print the array //
	for(int i=0 ; i<=a.size() ; i++)
	{
		for(int j=0 ; j<=b.size() ; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	// print the longest common subsequence //
	
	return arr[a.size()][b.size()];
}
int main()
{
	vector<char>a = {'a','b','c','b','d','a','b'};
	vector<char>b = {'b','d','c','a','b','a'};
	cout << LCS(a,b) << endl;
	return 0;
}
