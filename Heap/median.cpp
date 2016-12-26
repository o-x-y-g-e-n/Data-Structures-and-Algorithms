#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
void print(priority_queue<int>a)
{
	while(!a.empty())
	{
		cout << a.top() << " ";
	}
	cout << endl;
}
void add_no(priority_queue<int>&MAXVAL_minheap,priority_queue<int>&MINVAL_maxheap,int no)
{
	if(MAXVAL_minheap.size() == 0 || (-1)*no < MAXVAL_minheap.top())
	{
		MAXVAL_minheap.push((-1)*no);
	}
	else
		MINVAL_maxheap.push(no);
}
void rebalance(priority_queue<int> &MAXVAL_minheap,priority_queue<int> &MINVAL_maxheap)
{
	priority_queue<int>min_size =MAXVAL_minheap.size() > MINVAL_maxheap.size() ? MINVAL_maxheap : MAXVAL_minheap;
	priority_queue<int>max_size = MAXVAL_minheap.size() > MINVAL_maxheap.size() ? MAXVAL_minheap : MINVAL_maxheap;
	if(max_size.size() - min_size.size() >=2 )
	{
		min_size.push(abs(max_size.top()));
		max_size.pop();
	}
}
double find_median(priority_queue<int> MAXVAL_minheap , priority_queue<int> MINVAL_maxheap)
{
	priority_queue<int>min_size =MAXVAL_minheap.size() > MINVAL_maxheap.size() ? MINVAL_maxheap : MAXVAL_minheap;
	priority_queue<int>max_size = MAXVAL_minheap.size() > MINVAL_maxheap.size() ? MAXVAL_minheap : MINVAL_maxheap;
	if(max_size.size() == min_size.size())
	{
		return ((double)(abs(min_size.top())+abs(max_size.top())/2));
	}
	else
		return ((double)abs(max_size.top()));
}
int main()
{
	priority_queue<int> MAXVAL_minheap;
	priority_queue<int> MINVAL_maxheap;
	int a;			// no of values to be entered
	scanf("%d",&a);
	vector<double>median;
	for(int i=0 ; i<a ; i++)
	{
		int b;
		scanf("%d",&b);
		add_no(MAXVAL_minheap,MINVAL_maxheap,b);
		rebalance(MAXVAL_minheap,MINVAL_maxheap);
		median.push_back(find_median(MAXVAL_minheap,MINVAL_maxheap));
	}
	for(int i=0 ; i<a; i++)
		cout << median[i] << " ";
	cout << endl;
	return 0;
}
