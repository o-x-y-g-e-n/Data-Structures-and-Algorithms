
									// merge overlapping intervals 
										// time complexity O(nlogn)  // space complexity O(n)

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <ctype.h>
#include <functional>
using namespace std;
struct vertex
{
	int s , e;
};
bool fun(vertex a ,vertex b)
{
	//somewhat older version of lambda functions
	return a.s < b.s;
}
void mergeintervals(vector<vertex>a,vector<vertex>&res)
{
	sort(a.begin(),a.end(),fun);
	res.push_back(a[0]);
	for(int i=1 ; i<a.size() ; i++)
	{
		if(res.back().e >= a[i].s)
		{
			res.back().e = max(res.back().e,a[i].e);
		}
		else
		{
			res.push_back(a[i]);
		}
	}
}
int main()
{
	vector<vertex>a = {{6,8},{2,5},{1,3},{13,20},{9,14}};
	vector<vertex>res;
	mergeintervals(a,res);
	for(int i=0 ; i<res.size() ; i++)
	{
		cout << "(" << res[i].s << "," << res[i].e << ") ,";  
	}
	cout << endl;
	return 0;
}