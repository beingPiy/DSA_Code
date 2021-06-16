#include <iostream>
#include <vector>
using namespace std ;

class MinMaxStack{
    vector<int> min_stack ;
    vector<int> max_stack ;
    vector<int> s ;

    public:
        bool empty(){
            return !s.size() ;
        }
        void push(int data){
            int current_min = data ;
            int current_max = data ;

            if(s.empty()){
                min_stack.push_back(current_min) ;
                max_stack.push_back(current_max) ;
            }
            current_min = min(min_stack[min_stack.size()-1] , data) ;
            current_max = max(max_stack[max_stack.size()-1] , data) ;

            min_stack.push_back(current_min) ;
            max_stack.push_back(current_max) ;
            
            s.push_back(data) ;
        }

        int get_min(){
            return min_stack[min_stack.size()-1] ;
        }
        int get_max(){
            return max_stack[max_stack.size()-1] ;
        }

        void pop(){
            min_stack.pop_back() ;
            max_stack.pop_back() ;
            s.pop_back() ;
        }

        int top(){
            return s[s.size()-1] ;
        }
} ;

int main(){
    MinMaxStack s ;

    s.push(1) ;
    s.push(5) ;
    s.push(3) ;
    s.push(8) ;

    cout << s.get_max() << endl ;
    s.pop() ;
    cout << s.get_min() << endl ;
    cout << s.get_max() << endl ;
    s.pop() ;
    s.pop() ;
    cout << s.get_max() << endl ;
    cout << s.top() << endl ;

}