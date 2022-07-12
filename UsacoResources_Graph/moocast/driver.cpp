#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
vector<int> adj[MAXN];
bool check[MAXN];
int x[MAXN], y[MAXN], r[MAXN];
int dis = 0;
int n;

void dfs(int node){
    if(check[node] == true) return;
    check[node] = true;
    
    dis++;

    for(int u: adj[node]){
        if(!check[u]) {
            dfs(u);
        }
    }
    return;
}

void setup(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(r[i] * r[i] >= pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)){
                adj[i].push_back(j);
            }
        }
    }
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> x[i] >> y[i] >> r[i];
    }
    setup();
    int M = -1;
    for(int i = 0; i < n; i++){
        dfs(i);
        M = max(M, dis);
        dis = 0;
        fill(begin(check), end(check), false);
    }
    cout << M << endl;
}