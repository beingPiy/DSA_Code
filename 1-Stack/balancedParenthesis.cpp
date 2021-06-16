#include <iostream>
#include <stack>
using namespace std ;

bool isValid(char* s){
    stack<char> stk ;

    for(int i= 0 ; s[i] != '\0' ; i++){
        if(s[i] == '('){
            stk.push('(') ;
        }
        else if(s[i] == ')'){
            if(stk.empty() or stk.top() != '('){
                return false ;
            }
            stk.pop() ;
        }
    }
    return stk.empty() ;
}

int main(){
    char s[100] = "((a+b)*(c-d)))" ;

    if(isValid(s)){
        cout << "Yes" ;
    }
    else{
        cout << "No" ;
    }
}