#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};

class queue{

	node* front;
	node* rear;

public:

	queue(){
		front = rear = NULL;
	}

	void push(int val){
		node* ptr = new node(val);

		if(front == NULL){
			front = rear = ptr;
			return;
		}

		rear->next = ptr;
		rear = ptr;
	}

	void pop(){
		if(front == NULL){
			cout<<"Queue Underflow"<<endl;
			return;
		}

		node* to_del = front;
		front = front->next;
		delete to_del;
	}

	int peek(){
		if(front == NULL){
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		return front->data;
	}

	bool empty(){
		return front == NULL;
	}

};


int main(){

	queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.peek()<<endl;
	q.pop();
	cout<<q.empty()<<endl;
	
}