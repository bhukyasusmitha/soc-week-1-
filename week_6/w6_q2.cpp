#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int max = 100005;
vector<int> graph[max] ;
bool visit[max] ;
int par[max] ;
int cy_start = -1  ,cy_end = -1  ;

bool dfs(int node, int par) {
visit[node]= true;
par[node]= par;

for(int neighbor : graph[node]){
if(neighbor == par)  {continue; }  
if (visit[neighbor]) { cy_end = node; cy_start = neighbor;   return true ;}
if (dfs(neighbor, node)) { return true ;} }
return false ;  }

  int main(){
int n , m ;
cin >> n >> m ; 
 for (int i = 0; i < m; i++  ) {
int a , b ;
cin >> a >> b;
 graph[a].push_back(b);
graph[b].push_back(a);    }


for(int i = 1; i <= n; i++) {
if (!visit[i]) {  if (dfs(i, -1)) { break; }
    } }

 if (cy_start == -1) {cout << "IMPOSSIBLE" << endl;
    }
     else {
        vector<int> cycle;
        cycle.push_back(cy_start);
        int v = cy_end;
        while (v != cy_start) {
        cy.push_back(v);
        v = par[v] ;
        }
        cycle.push_back(cy_start); 
reverse(cycle.begin(), cycle.end());

cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";}
        cout << endl;
    }}
