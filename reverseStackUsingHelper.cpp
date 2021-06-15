#include <iostream>
#include <stack>
using namespace std ;

void transfer(stack<int> &s1 , stack<int> &s2 , int n){
    for(int i = 0 ; i < n ; i++){
        s2.push(s1.top()) ;
        s1.pop() ;
    }
}

void reverseStack(stack<int> &s1){
    int n = s1.size() ;
    stack<int> s2 ;

    for(int i = 0 ; i < n ; i++){
        int x = s1.top() ;
        s1.pop() ;

        // transfer n-i-1 elements from s1 to s2
        transfer(s1 , s2 , n-i-1) ;
        //push the x in bottom of s1
        s1.push(x) ;
        //transfer n-i-1 elements from s2 to s1
        transfer(s2 , s1 , n-i-1) ;
    }
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