#include <iostream>
using namespace std ;

class node{

public:
    int data ;
    node* next ;

//constructor
    node(int d){
        data = d ;
        next = NULL ;
    }

} ;

// by value head pointer is unchanged
void insertAtTail(node* &head , int data){
    if(head == NULL){
        head = new node(data) ;
        return ;
    }
    node* temp = head ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    node* n = new node(data) ;
    temp -> next = n ;
    return ;
}

void print(node* head){
    while(head != NULL){
        cout << head -> data << " -> " ;
        head = head->next ;
    }
    cout << endl ;
}

void deleteHead(node* &head){
    if(head == NULL){
        return ;
    }
    node* temp = head->next ;

    delete head ;

    head = temp ;
}

int main(){
    node* head = NULL ;
    insertAtTail(head , 3) ;
    insertAtTail(head , 2) ;
    insertAtTail(head , 1) ;
    insertAtTail(head , 0) ;

    print(head) ;

    deleteHead(head) ;

    print(head) ;

}