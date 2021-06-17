#include <iostream>
#include <cstring>
using namespace std ;

int main(){
    char a[] = "abccdefgd" ;

    int curr_len = 1 ;
    int max_len = 1 ;

    int visited[256] = {-1} ;
    visited[a[0]] = 0 ;
    int n = strlen(a) ;

    for(int i = 1 ; i < n ; i++){
        int last_occ = visited[a[i]] ;

        if(last_occ == -1 || i-curr_len > last_occ){
            curr_len++ ;
        }
        else{
            curr_len = i - last_occ ;
        }

        visited[a[i]] = i ;
        max_len = max(curr_len , max_len) ;
    }
    cout << max_len ;
}