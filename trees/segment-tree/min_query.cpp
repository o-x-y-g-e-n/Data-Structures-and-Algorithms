		// this is an use of segment tree
	// find minimum in the given range
						// time complexity --> 0(n) + 0(logn)
					//	0(n) --> to construct the tree;
				//		0(logn) --> per query

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <cstdio>
using namespace std;
#define SIZE 6
#define INF 99999999
int t[SIZE*3];
int arr[SIZE]= {2,5,1,4,9,3};
void build(int64_t node, int64_t a, int64_t b)
{
	// 1 index
	if(a>b) return;
	if (a==b)
	{
		t[node]=arr[a];
		return;
	}
	
	build(node*2, a, (a+b)/2);
	build(node*2+1,(a+b)/2+1,b);
	
	t[node]=min(t[node*2],t[node*2+1]);
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return INF;
    }
    if(l <= start and end <= r)
    {
        return t[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}
int main()
{
	build(1,0,SIZE-1);
	//for(int i=1 ;i<3*SIZE ;i++)
	//	cout << t[i] << " ";
	cout << query(1,0,SIZE-1,1,3) << endl;
}