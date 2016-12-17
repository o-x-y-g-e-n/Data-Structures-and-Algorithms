												//circular queue using arrays
																

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 4
using namespace std;
class que
{
private:
	int arr[MAX];
	int front = 0;
	int rear = 0;
public:
	void enqueue(int no)
	{
		rear = (rear + 1)%MAX;
		if(front == rear)
		{
			cout << "stack overflow " << endl;
			if(rear == 0)
			{
					rear = MAX-1;
			}
			else
				rear = rear -1;
			return ;
		}
		else
		{
				arr[rear] = no;
				return;
		}
	}
	int dequeue()
	{
		if(front == rear)
		{
			cout << "no more elements to delete" << endl;
			return -1;
		}
		else
		{
			front = (front +1)%MAX;
			return arr[front]; 
		}
	}
};
int main()
{
		que q;
		q.enqueue(1);
		q.enqueue(2);
		q.enqueue(3);
		cout << q.dequeue() << endl;
		q.enqueue(4);
		cout << q.dequeue() << endl;
		cout << q.dequeue() << endl;
		cout << q.dequeue() << endl;
		return 0;
}