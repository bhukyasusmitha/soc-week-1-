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
    
for (long long i=0 ; i<number ; i++){
         bool is = false ;
        if ( total[i]%2 !=0  && deno[i]%2 == 0 ) {cout << "NO\n" ; } 
        else if (total[i]%2 ==0  && deno[i]%2 == 0)  {
            for(long long y=0 ; y<= total[i] ; y++){       
                if ( (total[i] - deno[i]*y)%2 ==0 ){
                    is = true ; 
                    break ; 
                }
        }
        if (is) {
            cout << "YES\n" ; 
             
        } 
       
    
    if ( !is) {
        cout << "NO\n" ; 
}
    
}
 else if (total[i]%2 !=0  && deno[i]%2 != 0)  {
            for(long long y=1 ; y<= total[i] ; y+=2 ){       
                if ( (total[i] - deno[i]*y)%2 ==0 ){
                    is = true ; 
                    break ; 
                }
        }
        if (is) {
            cout << "YES\n" ; 
          
        } 
       
    
    if ( !is) {
        cout << "NO\n" ; 
}
    
}
else {for(long long y=0 ; y<= total[i] ; y+=2 ){       
                if ( (total[i] - deno[i]*y)%2 ==0 ){
                    is = true ; 
                    break ; 
                }
        }
        if (is) {
            cout << "YES\n" ; 
         
        } 
       
    
    if ( !is) {
        cout << "NO\n" ; 
}
    
}



 }}  }  
 
