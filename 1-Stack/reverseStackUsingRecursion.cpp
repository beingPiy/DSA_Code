#include <iostream>
#include <stack>
using namespace std ;

void insertAtBottom(stack<int> &s , int x){
    if(s.empty()){
        s.push(x) ;
        return ;
    }
    int data = s.top() ;
    s.pop() ;
    insertAtBottom(s , x) ;
    s.push(data) ;
}


void reverseStack(stack<int> &s1){
    if(s1.empty()){
        return ;
    }

    int x = s1.top() ;
    s1.pop() ;
    reverseStack(s1) ;
    insertAtBottom(s1 , x) ;
}

int main(){
    stack<int> s ;

    s.push(1) ;
    s.push(2) ;
    s.push(3) ;
    s.push(4) ;

    reverseStack(s) ;

    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop() ;
    }
    
}