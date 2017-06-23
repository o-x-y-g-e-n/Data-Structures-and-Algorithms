			// this is all about segment trees..
					/ to find the sum in the given range;;
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
int t[SIZE*3];
int arr[SIZE];
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
	
	t[node]=t[node*2]+t[node*2+1];
}
void update(int node, int start, int end, int idx, int val)
{
  	// update at ith index 0<i<SIZE-1
    if(start == end)
    {
        // Leaf node
        arr[idx] += val;
        t[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            update(2*node, start, mid, idx, val);
        }
        else
        {
            update(2*node+1, mid+1, end, idx, val);
        }
        t[node] = t[2*node] + t[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return t[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
int main()
{
	for(int i=0 ; i<SIZE ;i++)
		arr[i] = 1;
	build(1,0,SIZE-1);
	update(1,0,SIZE-1,1,2);
	for(int i=1 ;i<3*SIZE ;i++)
		cout << t[i] << " ";
}
