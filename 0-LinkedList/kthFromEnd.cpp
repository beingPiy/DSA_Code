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
        tail = tail->next ;
    }
    node* n = new node(data) ;
    tail->next = n ;
    
}

void print(node* head){
    while(head!= NULL){
        cout << head->data << " -> " ;
        head = head->next ;
    }
    cout << endl ;
}

node* kth(node* head , int k){
    int jump = 1 ;
    node* lag = head ;
    node* lead = head ;
    while(jump <= k-1){
        lead = lead->next ;
        jump++ ;
    }
    while(lead->next != NULL){
        lag = lag->next ;
        lead = lead->next ;
    }

    return lag ;
}

int main(){
    node* head = NULL ;
    insertAtTail(head , 3) ;
    insertAtTail(head , 2) ;
    insertAtTail(head , 1) ;
    insertAtTail(head , 0) ;
    insertAtTail(head , 5) ;

    int k ; 
    cin >> k ;

    print(head) ;
    cout << kth(head , k)->data ;
    
}