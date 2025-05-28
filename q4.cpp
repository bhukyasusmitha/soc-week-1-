#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lunumber(int a ) {
  int l = 0, s = 9;
    while (a > 0) {
        int d = a % 10;
        l = max(l, d);
        s = min(s, d);
        a /= 10;
    }
    return l - s;
 }
 
int main() {
    int number ;
    cin >> number ;
    int small[number] ;
    int large[number] ;
    for (int u=0 ; u <number; u++ ) {
        cin >> small[u] ;
        cin >> large[u] ;
    }
    
    
    for (int i=0 ; i<number ; i++){
        int ans = small[i];
        int mal = lunumber(small[i]);
        for(int u=small[i] ; u <=min (large[i], (small[i] + 100) ) ; u++) {
        int cu = lunumber(u);
            if (cu > mal ) {
                mal = cu;
                ans = u;
            }
            if (mal == 9) break;  
        }
 
        cout << ans << '\n';
    }
 
} 