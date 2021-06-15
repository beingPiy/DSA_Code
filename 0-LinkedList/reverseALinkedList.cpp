#include <iostream>
using namespace std ;

class node{

public :
    int data ;
    node* next ;

    node(int d){
        data = d ;
        next = NULL ;
    }

} ;

void insertAtTail(node* & head , int data){
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

    return ;
}

void print(node* head){
    while(head != NULL){
        cout << head->data << " -> " ;
        head = head->next ;
    }
    cout << endl ;
}

void reverse(node* &head){
    node* C = head ;
    node* P = NULL ;
    node* N ;

    while(C != NULL){
        // save the next node
        N = C->next ;
        //Change the next pointer of current to prev
        C->next = P ;
        // move ahead , prev to curr , curr to next
        P = C ;
        C = N ;
    }

    head = P ;
}



int main(){
    node* head = NULL ;

    insertAtTail(head , 3) ;
    insertAtTail(head , 2) ;
    insertAtTail(head , 5) ;
    insertAtTail(head , 4) ;
    insertAtTail(head , 1) ;
    insertAtTail(head , 0) ;

    print(head) ;

    reverse(head) ;

    print(head) ;
    
   

}