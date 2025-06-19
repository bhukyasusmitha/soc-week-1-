#include <iostream>
#include <vector>

using namespace std;


const int MOD = 1000000007;

int main() {
    int num;
    cin >> num;  

   
    vector<int> w(num + 1, 0);

 
    w[0] = 1;


    for (int  = 1; total <= num; total++) {
        
        for (int dice = 1; dice <= 6; dice++) {
    
            if (total - dice >= 0) {
    
                w[total] = (w[total] + w[total - dice]) % MOD;
            }
        }
    }

    
    cout << w[num] << endl;

    return 0;
}
