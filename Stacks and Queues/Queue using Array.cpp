#include<iostream>
using namespace std;

#define n 100

class queue{
	int* arr;
	int front;
	int rear;

public:
	queue(){
		arr = new int[n];
		front = rear = -1;
	}

	void push(int val){
		if(rear == n-1){
			cout<<"Queue overflow"<<endl;
			return;
		}
		if(front == -1){
			front++;
			rear++;
			arr[front] = val;
			return;
		}
		rear++;
		arr[rear] = val;
	}

	void pop(){
		if(front > rear){
			cout<<"Queue Underflow"<<endl;
			return;
		}

		front++;
	}

	int peek(){
		if(front == -1 || front == n){
			cout<<"Queue empty"<<endl;
			return -1;
		}
		return arr[front];
	}

	bool empty(){
		return (front == -1 || front > rear);
	}
};

int main(){
	queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	cout<<q.peek()<<endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
}