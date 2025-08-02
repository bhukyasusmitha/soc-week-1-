#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
int dist1[MAXN], dist2[MAXN];


void dfs(int node, int parent, int dist[], int current) {
    dist[node] = current;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, dist, current + 1);
        }
    }
}


int find_farthest(int start, int dist[]) {
    dfs(start, -1, dist, 0);
    int farthest = start;
    for (int i = 1; i < MAXN; ++i) {
        if (dist[i] > dist[farthest]) {
            farthest = i;
        }
    }
    return farthest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

   
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

   
    int nodeA = find_farthest(1, dist1);

  
    int nodeB = find_farthest(nodeA, dist1);  

   
    dfs(nodeA, -1, dist1, 0);
    dfs(nodeB, -1, dist2, 0);

   
    for (int i = 1; i <= n; ++i) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << "\n";

    return 0;
}
