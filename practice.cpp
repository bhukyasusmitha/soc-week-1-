#include<iostream>
#include <algorithm>
using namespace std;
int main() {
   int a;
    cin >> a;
    int arr[a];
 
    for (int y = 0; y < a; y++) {
        cin >> arr[y];
    }
    sort(arr,arr+ a ) ;
    int med =0 ;
    if ( a % 2  != 0 ) {
        med = arr[a-1/2] ; 
    } 
    else { med =( arr[a/2] + arr[(a-1)/2 ] ) / 2 ; }

    int totalcost =0 ;
    for ( int u =0 ; u < a ; u ++ ){
        totalcost += max(arr[u] , med ) - min (arr[u] , med ) ; 
    }

 cout << totalcost << endl ; 
    

}