			// this is the example of lazy propogation with the sum criteria..
			// and bro .. this is fuckin' workin' ;;;)))
				// time complexity per query --> 0(logn)
			// to construct the fuckin tree --> 0(n)
			/// being lazy costs motherfucker.. ;)
#include <iostream>
#include <string>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <climits>
using namespace std; 
int arr[100006];
int t[262200];
int lazy[262200];

void build(int node, int a, int b)
{
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

int query(int node, int a, int b, int i, int j)
{
	if(a>b||a>j||b<i) return 0;
	if (lazy[node] !=0 )
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if (a>=i && b<=j) return t[node];
	
	int q1=query(node*2, a, (a+b)/2, i, j);
	int q2=query(node*2+1, (a+b)/2+1, b, i, j);
	
	return q1+q2;
}

void update(int node, int a, int b, int i, int j, int inc)
{
	if(a>b) return;
	if (lazy[node]!=0)
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||a>j||b<i) return;
	
	if (a>=i && b<=j)
	{
		t[node]+=inc*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}
	
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int t,n,qu,q,p,a; cin>>t;
	int inc;
	while(t--)
	{
		cin>>n>>qu;
		for(int i=0 ; i<n ; i++)
			arr[i] = 1;
		build(1,0,n-1);
		for (int i = 0; i < 262200; ++i) lazy[i]=0;
		while(qu--)
		{
			for(int i=0 ; i<3*n ; i++)
			printf("%d ",arr[i]);
			cout << endl;
			cin>>a;
			if (a==0)
			{
				cin>>p>>q>>inc;
				update(1,0,n-1,p-1,q-1,inc);
			}
			else
			{
				cin>>p>>q;
				cout<<query(1,0,n-1,p-1,q-1)<<endl;
			}
		}
		
	}
	return 0;
} 