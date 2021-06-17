#include <iostream>
#include <queue>

using namespace std ;

int main(){
    queue<char> q ;

    char ch ;
    cin >> ch ;
    int freq[26] = {0} ;

    while(ch != '.'){
        q.push(ch) ;
        freq[ch-'a']++ ;

        while(!q.empty()){

            char front = q.front() ;
            if(freq[front-'a'] > 1){
                q.pop() ;
            }
            else{
                cout << "NonRepeatingChar - "<< front << endl ;
                break ;
            }
        }
        if(q.empty()){
            cout << "-1" << endl ;
        }
        cin >> ch ;
    }

    
}