#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
     vector<int> r(n);
      for (int i = 0; i < n; i++ )  cin >> r[i];
     double expinver = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++ ) {
            int ri = r[i];
            int rj = r[j];
            long long count = 0;
             if (ri <= rj) {
                for (int x = 1; x <= ri; ++x) {count += max(0, x - 1);} 
            } 
            else {
                for (int y = 1; y <= rj; ++y) {count += max(0, ri - y); } }
              double p = (double)count / (ri * rj);
            expinver += p;
        }
    }
expinver += 1e-9;
cout << fixed << setprecision(6) << expinver << '\n';   
}
