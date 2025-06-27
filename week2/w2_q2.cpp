#include <iostream>
#include <algorithm>
using namespace std ;
int main() {
long long x  , sum ;
cin >> x >> sum ; 
long long arr[x] ; 
long long duparr[x] ;
for (long long u = 0 ; u < x ; u ++){
cin >> arr[u] ; 
duparr[u] = arr[u] ; 

}
sort (arr , arr+x ) ; 
long long leftin =  0 ;
long long rightin = x-1 ;
long long one , two ; 
bool found = false ; 
while ( leftin < rightin ) {
    if( sum > (arr[leftin ] + arr[rightin]) ) {leftin ++ ; }
    else if ( sum < (arr[leftin ] + arr[rightin]) ) {rightin -- ; }
    else {   one = arr[leftin] ; two = arr[rightin]  ;  found = true ;break ;  }
    
}

if (found) {for (long long y =0 ; y < x ; y++) {
    if (one == duparr[y]) {cout << y + 1 << " " ;break ;  duparr[y]=0 ;  }  
    }
 
for (long long y =0 ; y < x ; y++) {
 if (two == duparr[y]) {cout << y+ 1  << " " ; break ; }
} }
 else {
cout << "IMPOSSIBLE" << endl ;  }
}