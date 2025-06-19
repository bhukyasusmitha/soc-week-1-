#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std ;
int main() {
   string alpha ;
   vector<char> seq ;
    getline(cin, alpha); 
    for (char ch : alpha) {
         if (isspace(ch) || seq.size() > 1000000 ) {
            break; 
        }
        seq.push_back(ch);
    }
    long long bre = 1;
    long long re = 1; 
    
    for (long long i=1 ; i < seq.size() ; i++) {
        if (seq[i-1] == seq[i]) {
           re ++ ;  
        }
        else {
            if (bre <= re) { bre = re ;}
            re = 1 ;
        }
    }
    if (bre < re) bre = re;
    cout << bre << "\n" ;  }
