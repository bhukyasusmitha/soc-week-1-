#include <bits/stdc++.h>
using namespace std;

const int MAXV = 200005; 

vector<int> adj[MAXV], radj[MAXV];
vector<bool> visited(MAXV);
vector<int> order, comp(MAXV), assignment;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int label) {
    comp[u] = label;
    for (int v : radj[u]) {
        if (comp[v] == -1) dfs2(v, label);
    }
}

int var(int x) {
    return x << 1;     
}
int neg(int x) {
    return x ^ 1;      
}

void add_clause(int a, bool sign_a, int b, bool sign_b) {
    int u = var(a) ^ (!sign_a);
    int v = var(b) ^ (!sign_b);
    // (!u => v) and (!v => u)
    adj[neg(u)].push_back(v);
    adj[neg(v)].push_back(u);
    radj[v].push_back(neg(u));
    radj[u].push_back(neg(v));
}

bool solve_2SAT(int vars) {
  
    for (int i = 0; i < 2 * vars; ++i) {
        if (!visited[i]) dfs1(i);
    }

    
    fill(comp.begin(), comp.begin() + 2 * vars, -1);
    int label = 0;
    for (int i = 2 * vars - 1; i >= 0; --i) {
        int u = order[i];
        if (comp[u] == -1) dfs2(u, label++);
    }

    
    assignment.resize(vars);
    for (int i = 0; i < vars; ++i) {
        if (comp[var(i)] == comp[neg(var(i))]) {
            return false; 
        }
        assignment[i] = comp[var(i)] > comp[neg(var(i))];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;


    for (int i = 0; i < n; ++i) {
        char s1, s2;
        int x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;
        --x1; --x2; 

        bool sign1 = (s1 == '+');
        bool sign2 = (s2 == '+');

        add_clause(x1, sign1, x2, sign2);
    }

    if (!solve_2SAT(m)) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < m; ++i) {
            cout << (assignment[i] ? '+' : '-');
        }
        cout << '\n';
    }

    return 0;
}
