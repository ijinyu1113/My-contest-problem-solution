#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int n, m;
vector<int> adj1[MAXN];
vector<int> adj2[MAXN];
vector<bool> visited(MAXN);

void G1(int node){
    if(visited[node]) return;
    visited[node] = true;

    for(int u: adj1[node]){
        if(!visited[u]){
            G1(u);
        }
    }
}

void G2(int node){
    if(visited[node]) return;
    visited[node] = true;

    for(int u: adj2[node]){
        if(!visited[u]){
            G2(u);
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        adj1[a-1].push_back(b-1);
        adj2[b-1].push_back(a-1);
    }
    G1(1-1);
    for(int i = 0; i < n; i ++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << "1" << " " << i+1 << endl;
            return 0;
        }
    }
    fill(visited.begin(), visited.end(), false);
    G2(1-1);
    for(int i = 0; i < n; i ++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i+1 << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}