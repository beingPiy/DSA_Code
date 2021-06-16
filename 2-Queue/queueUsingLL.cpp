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

void insertAtTail(node* &head ,int data){
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

void deleteHead(node* &head){
    if(head != NULL){
        node* temp = head ;
        head = head->next ;
        delete temp ;
    }
    else{
        cout << "Empty queue" ;
    }
}

int front(node* head){
    return head->data ;
}

void print(node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next ;
    }
    cout << endl ;
}


int main(){
    node* queue = NULL ;

    insertAtTail(queue , 1) ;
    insertAtTail(queue , 2) ;
    insertAtTail(queue , 3) ;
    insertAtTail(queue , 4) ;

    print(queue) ;


    deleteHead(queue) ;
    print(queue) ;

    deleteHead(queue) ;
    print(queue) ;


}