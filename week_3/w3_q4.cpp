#include<iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
string s1;
string s2;
cin >> s1 >> s2;
int n = s1.length();
int m = s2.length();  
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 for (int a =0; a <=n;a++) {
    dp[a][0]= a;}
 for (int l =0; l<=m;l++) {
    dp[0][l] = l; 
}

for (int i=1;i<=n;i++) {
    for (int j=1;j<= m;j++) {
    if (s1[i-1]==s2[j-1]) {
dp[i][j] =dp[i-1][j-1];} else {
int in_op =dp[i][j-1] + 1;
int de_op =dp[i-1][j]+ 1;
int re_op =dp[i-1][j-1] + 1;
dp[i][j] =min(in_op,min(de_op,re_op));
}}
    }
cout << dp[n][m] << endl;
}
