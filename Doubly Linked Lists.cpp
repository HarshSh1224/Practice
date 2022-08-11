#include<bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------
//                      DOUBLY LINKED LISTS
// ----------------------------------------------------------

class node
{
public:
    int data;
    node* next;
    node* previous;
    node(int data){
        this->data = data;
        next = NULL;
        previous = NULL;
    }    
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    if(head!=NULL)
    head->previous = n;

    head = n;
}

void insertAtTail(node* &head, int val){

    node* n = new node(val);
    node* temp = head;

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
}

void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(node* &head, int pos){
    
    node* temp = head;

    if(pos == 1){
        node* todelete = head;
        head = head->next;
        head->previous = NULL;
        delete todelete;
        return;
    }

    int count = 1;
    while(temp->next!=NULL && count<pos){
        temp = temp->next;
        count++;
    }

    temp->previous->next = temp->next;
    if(temp->next!=NULL)
    temp->next->previous = temp->previous;

    delete temp;

}

int main(){
    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);

    display(head);

    deletion(head, 7);

    display(head);
}