#include<bits/stdc++.h>
using namespace std;


//    CLASS NODE    //


class node
{  
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};



//   INSERTION    //



void insertAtTail(node* &head, int val){
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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}





//      SEARCHING FOR A VALUE      //





bool search(node* head, int val){
    while(head!= NULL){
        if(head->data == val) return true;
        head = head->next;
    }
    return false;
}




//      DISPLAY ENTIRE LL       //





void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}



//      DELETE A NODE          //




void Delete(node* &head, int val){

    if(head == NULL) return;

    node* temp = head;
    node* todelete;

    if(head->data == val){
        todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    while(temp->next!=NULL){
        if(temp->next->data == val){
            todelete = temp->next;
            temp->next = (temp->next)->next;
            delete todelete;
            return;
        }
        temp = temp->next;
    }
}




//      REVERSE THE LL COMPLETELY     //




node* reverse(node* &head){
    node* previous = NULL;
    node* current = head;
    node* nxt = head->next;

    while(nxt!=NULL){
        current->next = previous;

        previous = current;
        current = nxt;
        nxt = nxt->next;
    }
    current->next = previous;

    head = current;

    return head;
}




//      REVERSE K NODES IN A LL     //




node* reversek(node* head, int k){

    node* current = head;
    node* previous = NULL;
    node* nextptr;
    int count = 0;

    while(current!= NULL && count<k){
        nextptr = current->next;
        current->next = previous;

        previous = current;
        current = nextptr;

        count++;
    }

    if(current!=NULL)
    head->next = reversek(current, k);

    return previous;
}





//      CREATE CYCLE AT (pos)th POSITION    //




void createCycle(node* head, int pos){
    node* temp = head;
    node* startnode;
    int count = 1;

    while(temp->next != NULL){

        if(count == pos){
            startnode = temp;
        }

        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}



//      Detect Cycle in a LL      //



bool detectCycle(node* head){
    node* fast = head;
    node* slow = head;

    while(fast->next != NULL && fast!= NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return false;
    }

    return true;
}




//      Remove Cycle from a LL    //




void removeCycle(node* head){

    // we are assuming the the cycle IS present in the node

    node* fast = head;
    node* slow = head;

    while(fast->next != NULL && fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            break;
        }
    }

    fast = head;

    do{
        fast = fast->next;
        slow = slow->next;
    }while(fast->next != slow->next);

    slow->next = NULL;

}




int main(){
    
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    display(head);

    cout<<(search(head, 3)?"3? YES":"3? NO")<<endl;
    cout<<(search(head, 11)?"11? YES":"11? NO")<<endl;

    Delete(head, 3);
    display(head);

    // node* newhead = reverse(head);
    // display(newhead);

    

    // node* newhead2 = reversek(head, 3);

    display(newhead2);
 
    return 0;
}
