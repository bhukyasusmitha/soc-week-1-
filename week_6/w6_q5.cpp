#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

vector<int> graph[MAXN];
int in_degree[MAXN] = {0};
int dp[MAXN] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

   
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        in_degree[y]++;
    }

   
    queue<int> q;

    
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
           
            dp[v] = max(dp[v], dp[u] + 1);

            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

   
    int longest_path = 0;
    for (int i = 1; i <= n; ++i) {
        longest_path = max(longest_path, dp[i]);
    }

    cout << longest_path << '\n';

    return 0;
}
