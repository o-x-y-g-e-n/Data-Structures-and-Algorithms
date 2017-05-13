// 		to find k'th ugly no
// 	ugly no : the no that can be prime factorized only with 2,3 and 5 
// 	1 is an exception
// 	hence ugly nos are 1,2,3,4,5,6(3x3),8(2x2x2) etc
// ----------------------------------------------------------------
// time complexity --> 0(N) here 0(k)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main()
{
	int k = 10;
	vector<int>ugly(k,0);
	ugly[0] = 1;
	int a=0,b=0,c=0;
	for(int i=0 ; i<k-1 ; i++)
	{
		int z = min(min(ugly[a]*2 , ugly[b]*3) , ugly[c]*5);
		ugly[i+1] = z;
		if(z == ugly[a]*2)
			a++;
		if(z == ugly[b]*3)
			b++;
		if(z == ugly[c]*5)
			c++;
	}
	for(int i=0 ; i<10 ; i++)
	{
		cout << ugly[i] << " ";
	}
	
	return 0;
}
