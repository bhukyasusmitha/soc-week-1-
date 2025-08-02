#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;


ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}


ll mod_mul(ll a, ll b) {
    return (a % MOD) * (b % MOD) % MOD;
}


ll sum_of_sigma(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n; ) {
        ll q = n / i;
        ll j = n / q;
       
        ll count = j - i + 1;
        ll sum_d = ((i + j) % MOD) * (count % MOD) % MOD * ((MOD + 1) / 2) % MOD;
        res = mod_add(res, mod_mul(q, sum_d));
        i = j + 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    cout << sum_of_sigma(n) << "\n";
    return 0;
}
