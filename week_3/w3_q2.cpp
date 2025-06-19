#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool canmakepro(long long time, const vector<long long>& mac, long long t) {
    long long total = 0;

    for (long long machine : mac) {
        total += time / machine;
        if (total >= t) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int num;
    long long t;
    cin >> num >> t;

    vector<long long> mac(num);
    for (int i = 0; i < num; i++) {
        cin >> mac[i];
    }

    
    long long l  = 1;
    long long r  = 1e18; 
    long long answer = r;

    while (l <= r ) {
        long long mid = (l + r) / 2;

        if (canmakepro(mid, mac, t)) {
            answer = mid; 
            r = mid - 1;
        } else {
            l = mid + 1; 
        }
    }

    cout << answer << endl;

    return 0;
}
