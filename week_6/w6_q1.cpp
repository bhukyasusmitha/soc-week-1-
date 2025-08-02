#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int max=200005 ;
vector<int> graph[max] ;
bool guarded[max] ;
int maxsta[max]  ; 
int main()  {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int N, M, K;
cin>>N>>M>>K;

for (int i= 0; i < M; i ++ ) {
int a, b;
cin >> a >> b;
graph[a].push_back(b);
graph[b].push_back(a); }

priority_queue<pair<int, int>> pq;
  
for(int i= 0; i<K; i++ ) {
int p, h;
cin >> p>> h;
pq.push({h, p});
    maxsta[p] = h;
 guarded[p] = true;
    }

   while(!pq.empty()) {
    auto [sta, node] = pq.top();
    pq.pop();

        if (sta == 0) continue;

    for (int neigh : graph[node]) {
    if (maxsta[neigh] < sta - 1) {
        maxsta[neigh] = sta - 1;
                guarded[neigh] = true;
                pq.push({sta - 1, neigh});}
    }
    }

    
    vector<int> res;
    for (int i = 1; i < N + 1 ; i ++ ) {
    if (guarded[i]) {
     res.push_back(i);
        }
    }

   
 cout << res.size() << '\n';
 for (int v : res) {
 cout << v << ' '  ;
}
cout << '\n';   
}
