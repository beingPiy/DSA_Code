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

node* merge(node* a, node* b){
    // base case
    if( a  == NULL){
        return a ;
    }
    if(b == NULL){
        return b ;
    }

    // rec case
    node* c ;
    if(a->data < b->data){
        c = a ;
        c->next = merge(a->next , b) ;
    }
    else{
        c = b ;
        c->next = merge(a , b->next) ;
    }

    return c ;

}

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
    while(head != NULL){
        cout << head->data << " -> " ;
        head = head -> next ;
    }
    cout << endl ;
}

int main(){
    node* a = NULL ;
    node* b = NULL ;

    insertAtTail(a , 1 ) ;
    insertAtTail(a , 3) ;
    insertAtTail(a , 5) ;
    insertAtTail(a , 7) ;
    insertAtTail(a , 10) ;
    insertAtTail(a , 12) ;
    insertAtTail(b , 0 ) ;
    insertAtTail(b , 2 ) ;
    insertAtTail( b ,4) ;
    insertAtTail(b , 6 ) ;
    insertAtTail(b , 8 ) ;
    insertAtTail(b , 11 ) ;

    print(a) ;
    print(b) ;

    print(merge(a , b)) ;
    
}