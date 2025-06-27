#include<iostream>
#include<algorithm>
using namespace std ;
int main(){
    long long y , sum ;
    cin >> y >> sum ;
    long long arr[y] ;  
    long long duparr[y] ;
for (long long u = 0 ; u < y ; u ++) {
    cin >> arr[u] ; 
    duparr[u] = arr[u] ; 
}
sort(arr,arr+y) ; 
long long first = 0 , second = y-1 ; 
 
long long one , two , three = 1  ;  
bool found = false ;
while(first < second) { 
    if (arr[first] + arr[second] < sum ) {
        
        for (long long u = first+1  ; u < second ; u++) {
            if (arr[u]+ arr[first] + arr[second] == sum ){
                one =  arr[first] ; 
                two = arr[second] ;
                three = arr[u] ; 
                found = true ; 
                break ; 
 
 
            }
        }
 if (found) {
    break ; 
 }
 else {first ++ ; }
}
else  {
    second -- ; 
}
}
if (found){
 for (long long q =0 ; q < y ; q++) {
    if (one == duparr[q]) {cout << q + 1 << " " ; duparr[q] = -1;break ; }
}
 
for (long long q =0 ; q < y ; q++) {
    if (two == duparr[q]) {cout << q + 1  << " "; duparr[q] = -1 ;break ;}
}
for (long long q =0 ; q < y ; q++) {
    if (three == duparr[q]) {cout << q + 1  << endl ; break ;  }
} }
 
 
if (!found  ) {cout << "IMPOSSIBLE" ; }
}