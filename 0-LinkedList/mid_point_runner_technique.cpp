#include <iostream>
using namespace std ;

class node{
public:
    int data ;
    node* next ;

    node(int d){
        data = d ;
        next = NULL ;
    }
} ;

void insertAtTail(node* &head , int data){
    if(head == NULL){
        head = new node(data) ;
        return ;
    }
    node* tail = head ;
    while(tail->next != NULL){
        tail = tail -> next ;
    }
    node* n = new node(data) ;
    tail->next = n ;
}

void print(node* head){
    while(head != NULL){
        cout << head->data << " -> " ;
        head = head -> next ;
    }
    cout << endl ;
}

node* midPoint(node* head){
    node* slow = head ;
    node* fast = head->next ;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow ;

}

int main(){
    node* head = NULL ;

    insertAtTail(head , 3) ;
    insertAtTail(head , 2) ;
    insertAtTail(head , 1) ;
    insertAtTail(head , 0) ;
    insertAtTail(head , 5) ;
    insertAtTail(head , 4) ;

    print(head) ;

    cout << midPoint(head)->data ;

    return 0 ;
}