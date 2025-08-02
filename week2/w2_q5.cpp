#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int a;
    cin >> a;
    int arr[a];
 
    for (int y = 0; y < a; y++) {
        cin >> arr[y];
    }
 
    sort(arr, arr + a);
 
    int med = 0;
    if (a % 2 != 0) {
        med = arr[ (a-1) / 2];
    } else {
        med = (arr[a / 2] + arr[(a / 2) - 1]) / 2;
    }
 
    int po = 0;
    for (int i = 0; i < a; i++) {
        po += max(med, arr[i]) - min(med, arr[i]); 
    }
 
    cout << po;
}  
