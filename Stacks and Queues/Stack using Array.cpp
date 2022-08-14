#include<bits/stdc++.h>
using namespace std;

#define n 100

class stacck{

	int* arr; // dynamic array
	int top;  // store the index in stack

public:

	stacck(){
		arr = new int[n];
		top = -1;
	}

	void push(int x){
		if(top == n-1){
			cout<<"Stack Overflow"<<endl;
			return;
		}

		top++;
		arr[top] = x;
	}

	void pop(){
		if(top == -1){
			cout<<"Stack is empty"<<endl;
			return;
		}
		top--;
	}

	int Top(){
		if(top == -1){
			cout<<"Stack is empty"<<endl;
			return -1;
		}

		return arr[top];
	}

	bool empty(){
		return top==-1;
	}
};


int main(){

	stacck stck;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);

	cout<<stck.Top()<<endl;
	stck.pop();
	cout<<stck.Top()<<endl;
	stck.pop();
	cout<<stck.Top()<<endl;
	stck.pop();
	cout<<stck.Top()<<endl;
	stck.pop();
	cout<<stck.empty()<<endl;
	stck.pop();

}