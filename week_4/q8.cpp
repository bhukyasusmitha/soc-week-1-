#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
ll mod_pow(ll base, ll exp, ll mod = MOD){
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod; base = base * base % mod;  exp >>= 1; }
    return res;
}
ll mod_inv(ll a, ll mod = MOD) {  return mod_pow(a, mod - 2, mod); }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
vector<pair<ll, ll>> primes(n);
for (int i = 0; i < n; ++i) {
 cin >> primes[i].first >> primes[i].second; }

    ll numdivi= 1;
    ll sumdivi= 1;
    ll expomod= 1;        
    bool even= false;  
    for (auto &[p,k]:primes) {numdivi = numdivi*(k+1)% MOD  ;
    ll numerator =mod_pow(p, k + 1) - 1;
    if (numerator< 0) numerator+=MOD;
    ll denominator= mod_inv(p-1);
    ll term = numerator * denominator % MOD;
    sumdivi = sumdivi * term % MOD;
    }
ll base = 1;
     for (auto &[p, k] : primes) {
     base = base * mod_pow(p, k) % MOD; }

   ll tdm = 1;  for (auto &[p, k] : primes) {
        tdm = tdm * (k + 1) % (MOD - 1);
    }
    ll pexpo = tdm;
    if (pexpo % 2 == 0) {  pexpo= pexpo / 2;
    } else {
         for (auto &[p, k] : primes) {
            if ((k + 1) % 2 == 0) {  ll exp = 1;
            for (auto &[p2, k2] : primes) {
                if (p == p2 && k == k2) {
                    exp = exp * ((k2 + 1) / 2) % (MOD - 1);} 
                    else {
                    exp = exp * (k2 + 1) % (MOD - 1);
                    } } pexpo = exp;
                break; } }  }


 ll pd = mod_pow(base, pexpo );
 cout << numdivi << " " << sumdivi << " " << pd << '\n';

}
