#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std ;
int main () {
    long long x ;
    cin >> x ; 
    if ( x >=1 && x<= 1000000) {
        cout << x << " " ; 
        while ( x > 1 ) {
            if ( x %2 ==1 ) {
                x = (x*3) + 1 ;
                cout << x << " " ; 
            }
            else {
                x = x/2 ;
                cout << x  << " " ; 
            }
        }
        
    }
}                                                                                 