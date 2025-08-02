#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int in[MAXN], subtree_size[MAXN];
vector<int> dfs_order;
int timer = 0;

void dfs(int node) {
    in[node] = timer++;
    dfs_order.push_back(node);
    subtree_size[node] = 1;

    
    sort(tree[node].begin(), tree[node].end());

    for (int child : tree[node]) {
        dfs(child);
        subtree_size[node] += subtree_size[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

   
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

   
    dfs(1);

  
    while (q--) {
        int u, k;
        cin >> u >> k;

        if (k > subtree_size[u]) {
            cout << -1 << '\n';
        } else {
            cout << dfs_order[in[u] + k - 1] << '\n';
        }
    }

    return 0;
}
