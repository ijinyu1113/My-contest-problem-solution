#include<bits/stdc++.h>

using namespace std;
const int MN = 1E5;
vector<pair<int, int>> adj[MN];
vector<int> visited(MN);

int n, m;
int ans = 1;
int flag = 1;

void dfs(int p, int team){
    visited[p] = team;

    for(auto u: adj[p]){
        int k = u.first;

        if(visited[k] == 0){
            if(u.second == 2) {
                ans *= 2;
                if(team == 1) team = 2;
                else team = 1;
                dfs(k, team);
                if(team == 1) team = 2;
                else team = 1;
            }
            else{
                dfs(k, team);
            }
            
        }

    }
    
}

int main(){
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        char a;
        int x, y;
        cin >> a >> x >> y;
        x--; y--;
        if(a == 'S') {
            adj[x].push_back(make_pair(y, 1));
            adj[y].push_back(make_pair(x, 1));
        }
        else{
            adj[x].push_back(make_pair(y, 2));
            adj[y].push_back(make_pair(x, 2));
        }
    }
    int team = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0) dfs(i, team);
    }
    
    if(flag == 0) {
        cout << "0" << endl;
    }

    else{
        cout << "1";
        for(int i = ans; i>1; i--){
            cout << "0";
        }
    }
    //cout << ans << endl;
}