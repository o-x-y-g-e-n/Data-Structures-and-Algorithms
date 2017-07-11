#include <bits/stdc++.h>
using namespace std;
 
#define maxn 1000005
#define INF 99999999
 
int smallest_prime[maxn];
int divisors[maxn];
int segmentTree[4 * maxn];
 
void findSmallestPrimeFactors()
{
    for (int i = 0 ; i < maxn ; i ++ )
        smallest_prime[i] = INF;
 
    for (long long i = 2; i < maxn; i++)
    {
        if (smallest_prime[i] == INF)
        {
            smallest_prime[i] = i;
            for (long long j = i * i; j < maxn; j += i)
                if (smallest_prime[j] > i)
                    smallest_prime[j] = i;
        }
    }
}
 void buildDivisorsArray()
{
    for (int i = 1; i < maxn; i++)
    {
        divisors[i] = 1;
        int n = i, p = smallest_prime[i], k = 0;
         while (n > 1)
        {
            n = n / p;
            k ++;
 
            if (smallest_prime[n] != p)
            {
                //use p^k, initialize k to 0
                divisors[i] = divisors[i] * (k + 1);
                k = 0;
            }
 
            p = smallest_prime[n];
        }
    }
}
 
void buildSegtmentTree(int node, int a, int b)
{
    // leaf node
    if (a == b)
    {
        segmentTree[node] = divisors[a];
        return ;
    }
 
    //build left and right subtree
    buildSegtmentTree(2 * node, a, (a + b) / 2);
    buildSegtmentTree(2 * node + 1, ((a + b) / 2) + 1, b);
    segmentTree[node] = max(segmentTree[2 * node],segmentTree[2 *node + 1]);
}
 
int query(int node, int a, int b, int l, int r)
{
    if (l > b || a > r)
        return -1;
 
    if (a >= l && b <= r)
        return segmentTree[node];
 
    return max(query(2 * node, a, (a + b) / 2, l, r),
               query(2 * node + 1, ((a + b) / 2) + 1, b,l,r));
}
 
int main()
{
    findSmallestPrimeFactors();
 
    buildDivisorsArray();
   buildSegtmentTree(1, 1, maxn - 1);
 
    cout << "Maximum divisors that a number has "
         << " in [1, 100] are "
         << query(1, 1, maxn - 1, 1, 100) << endl;
 
 
    cout << "Maximum divisors that a number has"
         << " in [10, 48] are "
         << query(1, 1, maxn - 1, 10, 48) << endl;
 
 
    cout << "Maximum divisors that a number has"
         << " in [1, 10] are "
         << query(1, 1, maxn - 1, 1, 10) << endl;
 
    return 0;
}