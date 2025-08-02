#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD - 1; 


ll binpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            if (b == 0 && c == 0)
                cout << 1 << '\n'; 
            else
                cout << 0 << '\n'; 
        } else {
            if (b == 0)
                cout << 1 << '\n'; 
            else {
                
                ll exponent = binpow(b, c, MOD2);
                ll result = binpow(a, exponent, MOD);
                cout << result << '\n';
            }
        }
    }

    return 0;
}
