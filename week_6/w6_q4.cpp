#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 200005;
vector<int> gra[MAX];
bool vited[MAX];
void dfs(int node) {
vited[node] = true;
 for(int nei : gra[node]) {
        if (!vited[nei]) {dfs(nei);  } }
  }

int main(){
    int t;
    cin >> t;
 while (t--) {int n;cin >> n;
     for (int i = 1; i <= n; i++) {
         gra[i].clear();  vited[i] = false;  }

    for (int i = 1; i <= n; i++) {int nei; cin >> nei;
            gra[i].push_back(nei);
            gra[nei].push_back(i); }

            int coneccomp = 0;
            for (int i = 1; i <= n; i++) { if (!vited[i]) {dfs(i);coneccomp++;
        }
        }
        int mindan = coneccomp;
        int maxdan = 0;
        vector<bool> counted(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!counted[i]) { int j = gra[i][0];
            if (gra[j].size() == 1 && gra[j][0] == i && !counted[j]) { maxdan ++;
                    counted[i] = true;
                    counted[j] = true;}}}
            maxdan += mindan- maxdan;
            cout << mindan << " " << maxdan << endl;  }

   
}
