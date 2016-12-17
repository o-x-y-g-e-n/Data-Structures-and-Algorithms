

						// implementing queue using two stack

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class que
{
private:
	stack<int>s1;
	stack<int>s2;
public:
	void enqueue(int no)
	{
			s1.push(no);
	}
	int dequeue()
	{
			int x;
			if(s2.empty())
			{
				if(s1.empty())
				{
					cout << "queue empty" << endl;
					return -1;
				}
				else
				{
					while(!s1.empty())
					{
						x = s1.top();
						s1.pop();
						s2.push(x);
					}
				}
			}
			 x = s2.top();
			 s2.pop();
			return x;
	}
};
int main()
{
	que q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.enqueue(5);
	cout << q.dequeue() << endl;
	return 0;
}