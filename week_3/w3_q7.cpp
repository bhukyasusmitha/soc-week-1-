#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

int main() {
    long long x;
    int num;
    cin >> x >> num;

   
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

   
    for (int i = 0; i < num; i++) {
        long long le;
        cin >> le;
        miheap.push(le); 
    }

    long long tocost = 0;

    
    while (miheap.size() > 1) {
        long long smallest = miheap.top();
        miheap.pop();

        long long secSmallest = miheap.top();
        miheap.pop();

        long long newstick = smallest + secSmallest;
        tocost += newstick;

        miheap.push(newstick);
    }

 
    cout << tocost << endl;

    return 0;
}
