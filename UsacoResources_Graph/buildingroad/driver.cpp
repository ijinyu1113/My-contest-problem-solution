#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adj[MAXN];
bool check[MAXN];
//vector<int> number[MAXN];
int n, m, rep[MAXN];
//int r = 1;

void dfs(int node){
    if(check[node]) return;
    check[node] = true;
    //number[r].push_back(node);

    for(int u: adj[node]){
        if(!check[u]) {
            dfs(u);
        }
    }
}

int comp_count(){
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(!check[i]){
            rep[cnt] = i;
            dfs(i);
            cnt++;
            //r++;
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = comp_count() - 1;

    cout << ans << endl;
    for(int i = 1; i < ans; i ++){
        cout << rep[i - 1] << " " << rep[i];
    }
}
//complete the two first problems