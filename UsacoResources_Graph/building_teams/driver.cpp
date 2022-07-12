#include <bits/stdc++.h>

using namespace std;
const int MN = 1E5;
vector<int> adj[MN];
vector<int> visited(MN);
int n, m;
int flag = 1;

void dfs(int person, int team){
    //if(visited[person] != 0) return;
    visited[person] = team;

    for(int u: adj[person]){ //person 0: friend 1 & 2
        if(visited[u] == team){
            flag = 0;
            //cout << u << " " << visited[u] << endl;
            return;
        }
        else if(visited[u] == 0){
            if(team == 1) team = 2;
            else team = 1;
            dfs(u, team);
            if(team == 1) team = 2;
            else team = 1;
        }
    }
}

int main(){
    int k;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        k = b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++){
        if(visited[i] == 0) dfs(i, 1);
    }
    
    if(flag == 0) cout << "IMPOSSIBLE";
    else{
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) cout << "1 ";
            else cout << visited[i] << " ";
        }
    }
}