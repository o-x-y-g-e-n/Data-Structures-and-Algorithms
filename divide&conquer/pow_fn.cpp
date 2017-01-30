
				// power function
				// time complexity --> 0(logn)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
using namespace std;
int temp= 0;
int pow(int x ,int n)
{
	if(n == 0)
		return 1;
	temp = pow(x,n/2);
	if(n % 2 == 0)
	{
		return temp * temp;
	}
	else
		return temp * temp *x;
}
int main()
{
	cout << pow(2,3) << endl;
	return 0;
}