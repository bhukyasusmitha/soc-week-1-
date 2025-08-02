#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
     while (t--) { int n;  cin >> n;  int xosu = 0 ;
        for (int i = 0; i < n; ++i) {  int x;  cin >> x;   xosu = xosu^x;  }
         cout << (xosu != 0 ? "first" : "second") << '\n';  }

   
}
