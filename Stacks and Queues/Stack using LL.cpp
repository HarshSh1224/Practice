#include<bits/stdc++.h>
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


void push(int val, node* &head){
	node* n = new node(val);

	if(head == NULL){
		head = n;
		return;		
	}

	node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = n;
}


int Top(node* head){
	node* temp = head;
	
	if(head == NULL){
		cout<<"Stack is empty"<<endl;
		return -1;
	}

	while(temp->next != NULL){
		temp = temp->next;
	}

	return temp->data;
}

void pop(node* &head){

	if(head == NULL){
		cout<<"Stack is empty"<<endl;
		return;
	}
	if(head->next == NULL){
		node* todelete = head;
		head = NULL;
		delete todelete;
		return;
	}

	node* temp = head;

	while(temp->next->next != NULL){
		temp = temp->next;
	}

	node* todelete = temp->next;
	temp->next = NULL;

	delete todelete;
}

bool empty(node* head){
	return head == NULL;
}


int main(){
	
	node* head = NULL;

	push(50, head);
	push(60, head);
	push(70, head);
	push(80, head);
	push(90, head);
	push(40, head);
	push(30, head);
	cout<<Top(head)<<endl;
	cout<<empty(head)<<endl;
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	pop(head);
	cout<<empty(head)<<endl;
	cout<<Top(head)<<endl;
}