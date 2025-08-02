#include <iostream>
 
using namespace std ;
int main() {
    long long  number ;
    cin >> number ;
if ( number >= 1  && number <= 10000 ) {
    long long  total[number] ;
    long long deno[number] ;
    for (long long u=0 ; u <number; u++ ) {
    long long x ;
   long long y ;
        cin >> x ;
        cin >> y ; 
     if ( x >= 1 && y >= 1 && x<= 1000000000000000000 && y <= 1000000000000000000 && x >= y && y != 2  ) {
 
        total[u] = x ;
        deno[u]  = y ; 
}
else { break ; }
    }
  






}
}