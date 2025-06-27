#include <iostream>
#include <vector>
using namespace std;


const int MOD = 1000000007;

int main() {
int num ;
cin >> num ; 
vector<int> ways(num + 1, 0);
ways[0] = 1;
for (int total = 1; total <= num; total++) {
    for (int dice = 1; dice <= 6; dice++) {
 if (total - dice >= 0) {
ways[total] = (ways[total] + ways[total - dice]) % MOD;
    }}
    }
cout << ways[num] << endl;

   
}
