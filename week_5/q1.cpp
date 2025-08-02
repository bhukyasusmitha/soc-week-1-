#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
string s;
cin >>s;
int n=s.length();
vector<int>dp(n, 0); 
int maxlen = 0;
int count= 0;

for (int u = 1; u < n; u++) {
    if (s[u] == ')') {
    int y = u -1 -dp[u- 1]; 
        if (y>= 0 && s[y] == '(') {
            dp[u]= dp[u - 1] + 2;
            if (y -1 >= 0) {
                dp[u]+= dp[y - 1]; 
                }
            }
        }

    if(dp[u] >maxlen){
        maxlen = dp[u];
        count = 1;
        } else if (dp[u] == maxlen && maxlen > 0) {
        count++;
        }
    }

    if(maxlen == 0){
    cout<< "0 1" << endl;
    }
    else {
cout <<maxlen <<" " <<count <<endl;}

   
}
