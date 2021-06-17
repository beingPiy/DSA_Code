#include <iostream>
#include <deque>

using namespace std ;

int main(){

    int n , k ;
    cin >> n ;
    int a[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    cin >> k ;

    // deque for a window push max in front
    deque<int> Q(k) ;

    // process first k elements
    int i ;
    for(i = 0 ; i < k ; i++){
        while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back() ;      
        }
        Q.push_back(i) ;
    }

    // Remaining elements

    for( ; i < n ; i++){
        cout << a[Q.front()] << " " ;
        // 1. Remove the elements which are no more part of window
        while(!Q.empty() && Q.front() <= i-k){
            Q.pop_front() ;
        }

        // 2. Remove the elements which are not useful for window
        while(!Q.empty() && a[Q.back()] <= a[i]){
            Q.pop_back() ;
        }

        // 3. Now push_back the element
        Q.push_back(i) ;
    }
    cout << a[Q.front()] << " " ;

}