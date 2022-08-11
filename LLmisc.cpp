#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(node* &head){
    node* temp = head;
    int total = 1;
    while(temp->next!=NULL){
        temp = temp->next;
        total++;
    }
    return total;
}

void appendK(node* &head, int k){

    node* temp = head;
    int len = length(head);

    k %= len;
    if(k==0) return;

    int count = 1;
    node* newtail;

    while(temp->next!=0){

        if(count == len-k){
            newtail = temp;
        }

        temp = temp->next;
        count++;
    }

    // node* newhead = newtail->next;
    temp->next = head;
    head = newtail->next;
    newtail->next = NULL;
}

void intersect(node* head, node*head2, int val){

    node* temp = head2;

    while(temp!=NULL && temp->data!=val){
        temp = temp->next;
    }

    node* temp2 = head;

    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp;
}

int Find_intersect(node* head, node* head2){

    int l1 = length(head);
    int l2 = length(head2);

    node* ptr1 = head;
    node* ptr2 = head2;
    if(l1 < l2) swap(ptr1,ptr2);
    int d = abs(l1-l2);

    while(d--){
        if(ptr1 == NULL) return -1;
        ptr1 = ptr1->next;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2) return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

node* merge(node* head, node* head2){
    node* dummy = new node(0);

    node* maxm = new node(INT_MAX);

    node* ptr1 = head;
    node* ptr2 = head2;
    node* ptr3  = dummy;

    while(ptr1!=maxm || ptr2!=maxm){

        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;

        ptr1 = ptr1 == NULL ? maxm: ptr1;
        ptr2 = ptr2 == NULL ? maxm: ptr2;
    }

    return dummy->next;

}

int main(){

    node* head = NULL;
    node* head2 = NULL;

    // int arr[] = {1,2,3,4,5,6};

    for(int i = 1; i<=5; i++){
        insertAtTail(head, i);
        insertAtTail(head2, i+3);
    }

    display(head);
    display(head2);

    // intersect(head2, head, 3);
    display(head2);

    // cout<<Find_intersect(head, head2)<<endl;

    node* merged = merge(head,head2);
    display(merged);

    cout<<length(merged);


} 