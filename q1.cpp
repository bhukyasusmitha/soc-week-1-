#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std ;
int main() {
    long long num ;
    cin >> num ;
    if ( num >=2 && num <= 200000) { 
        long long sum = (num*(num+1) )/2 ; 
         
        long long actual = 0 ;
        long long n ;
        for ( long long i =1 ; i < num ; i++) {
             cin >> n ;
             actual = actual  + n ;
        }
        cout << sum - actual << "\n" ; 
    } }  
