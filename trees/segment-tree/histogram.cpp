#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

#define test()    int test_case;cin>>test_case;while(test_case--)
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,n) for(int i=a;i<n;i++)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define si(a) scanf("%i",&a)
#define sd(a)  scanf("%ld",&a)
#define sf(a) scanf("%f",&a)
#define rn(a) return a
#define pai pair<int,int>
#define pal pair<li,li>
#define pall pair<lli,lli>
#define ff first
#define ss second
#define mod  1000000007
#define mp make_pair
#define pb push_back
#define pll(a) printf("%lld\n",a)
#define pl(a) printf("%lld\n",a)
#define pi(a) printf("%d\n",a)
#define pd(a) printf("%lf\n",a)
#define pf(a) printf("%f\n",a)
#define lc (start+end)/2
#define rc  lc+1

#include<iostream>

lli ans=0;
 int n;
using namespace std;
lli arr[1010000];
struct abcd
{
 int val;
 int index;
}tree[1010000];

int laz[10100000];
#define inf 999999999
abcd query(int node,int start,int end,int r1,int r2)
 {
  
   if(r1>end  || r2<start   || start>end) 
   {
    abcd node;
    node.index=INT_MAX;
    node.val=INT_MAX;
    return node;
   }
   if(r1<=start && r2>=end)
    {
     return tree[node];
     
    }
    else
    {
     abcd q1=query(2*node,start,(start+end)/2,r1,r2);
    abcd q2=query(2*node+1,((start+end)/2)+1,end,r1,r2);
     if(q1.val<=q2.val)return q1;
     else return q2;
    }
 }
 
 
 
void build(int node , int start,int end)
 {
  //cout<<" build start "<<start<<" "<<end<<endl;
  
   if(start>end) return ;
   if(start==end)
    {
     tree[node].index=start;
     tree[node].val=arr[start];
 }
  else
   {
    build(2*node,start,(start+end)/2);
    build(2*node+1,((start+end)/2)+1,end);
    if(tree[2*node].val<=tree[2*node+1].val)
    {
     tree[node].val=tree[2*node].val;
     tree[node].index=tree[2*node].index;
      
 }
 else
 {
  
    
     tree[node].val=tree[2*node+1].val;
     tree[node].index=tree[2*node+1].index;
 
 }
    
   }
   
 }
 
 int t=10;
 lli  solve(int start,int end)
  {
   //if(t--==0) exit(0);
  lli  ans=0;
   // cout<<"solve in the range "<<start<<" "<<end<<endl;
    if(start==end)
     {
      ans=max(ans,arr[start]);
      return ans;
      
  }
  else if(start>end)
   {
    return 0 ;
   }
   else
   {
    
    abcd node=query(1,0,n-1,start,end);
    int index=node.index;
   //  cout<<" index"<<index<<endl;
     if(index==start)
      {
    //   cout<<"ans set here "<<(end-start+1)*arr[index];
       ans=max(ans,max((end-start+1)*arr[index],solve(index+1,end)));
       
       
      }
      else if(index==end)
       {
         ans=max(ans,max(ans*(end-start+1)*arr[index],solve(0,end-1)));
    }
    else
    {
     ans=max(ans,max((end-start+1)*arr[index],max(solve(start,index-1),solve(index+1,end))));
    }
    
    return ans;
   }
   return ans;
  }

int main()
{

  cin>>n;
  for(int i=0;i<n;i++)
   {
     cin>>arr[i];
     
   }
//   cout<<" before bouid ";
   build(1,0,n-1);
//   cout<<"after build "<<endl;
   
  int fin=solve(0,n-1);
  cout<<fin<<endl;
}