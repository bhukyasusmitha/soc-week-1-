#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1000000007;
const int max = 100005;

vector<int> graph[max];
int indeg[max];
long long way[max];

int main() {
 int n, m ;
cin >> n >> m;

 for (int i = 0; i < m; i++) {
 int a, b;
cin >> a >> b;
graph[a].push_back(b);
indeg[b]++; }

queue<int> q;
way[1] = 1;
for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {q.push(i);} }

while (!q.empty()){int curr =q.front();q.pop();
     for (int next : graph[curr]) {
            way[next] =(way[next] +way[curr]) % MOD;
            indeg[next]--;
            if (indeg[next] == 0) { q.push(next);} }  }

cout << way[n] << endl;

    
}
