#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10E5;
vector<int> adj[MAXN];
vector<bool> check(MAXN);
int n, m;
int x_max, x_min, y_max, y_min;
struct coor{
    int x;
    int y;
};
coor nodes[MAXN];

void dfs(int node){
    if(check[node] == true) return;
    check[node] = true;

    x_max = max(x_max, nodes[node].x);
    x_min = min(x_min, nodes[node].x);
    y_max = max(y_max, nodes[node].y);
    y_min = min(y_min, nodes[node].y);
    
    for(int u: adj[node]){
        if(!check[u]){
            dfs(u);
        }
    }

    return;
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> nodes[i].x >> nodes[i].y;
    }
    
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int peri_min = INT_MAX;
    for(int i = 0; i < n; i++){
        x_max = y_max = -1;
        x_min = y_min = INT_MAX;
        if(!check[i]) {
            dfs(i);
            //cout << x_max << " " << x_min << " " << y_max << " " << y_min << " ";
            //cout << endl;
        
            int perimeter = 2 * (x_max - x_min + y_max - y_min);
            //cout << "per: " << perimeter << endl;
            peri_min = min(perimeter, peri_min);
        }
    }
    cout << peri_min << endl;
}