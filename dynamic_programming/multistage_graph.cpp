
                        // mutligraph algorithm -- dynamic programming
                        // time completixty --> o(n^2) == o(v^2) == 0(E)
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SIZE 8
#define MAX 999
using namespace std;
int arr[SIZE][SIZE] = {{0,1,2,5,0,0,0,0},{0,0,0,0,4,11,0,0},{0,0,0,0,9,5,16,0},{0,0,0,0,0,0,2,0},{0,0,0,0,0,0,0,18},{0,0,0,0,0,0,0,13},{0,0,0,0,0,0,0,2},{0,0,0,0,0,0,0,0}};
int edge_dist(int a , int b)
{
    return arr[a][b];
}
int main()
{
        int min = 0,tempans = 9999,r;
        int ans[SIZE];
        int d[SIZE];
        int p[4];
        ans[SIZE-1] = 0;
        set<int>back;
        for(int i = SIZE-2 ; i>=0 ; i--)
        {
            min = 999;
            tempans = 9999;
            r = 0;
            for(int j=i ;j<=SIZE-1 ; j++)
            {
                min = 999;
                int x = edge_dist(i,j);
                if(x != 0)
                {
                    min = x;
                }
                if(min + ans[j] < tempans)
                {
                    tempans = min + ans[j];
                    r = j;
                }
            }
            ans[i] = tempans;
            d[i] = r;
        }
        p[0] = 0;
        p[3] = 7;
        // printing ans                             /// hhhhhoooooowwwww ????????
        for(int i=1 ; i<=2 ; i++)
        {
            p[i] = d[p[i-1]];
        }
        for(int i=0 ; i<8 ; i++)
            cout << d[i] << " ";
            cout << endl;
        for(int i=0 ; i<4 ; i++)
            cout << p[i] << " ";
        return 0;
}