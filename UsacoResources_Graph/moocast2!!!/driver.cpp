#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int n;
vector<long long> dist[MAXN];
vector<bool> visited(MAXN);
pair<int, int> coor[MAXN];


void dfs(int node, long long x){
    if(visited[node]) return;
    visited[node] = true;

    for(int i = 0; i < n;i++){
        if(node == i) continue;
        if(dist[node][i] <= x && !visited[i]){
            dfs(i, x);
        }
    }
}

bool check(long long dig){
    fill(visited.begin(), visited.end(), 0);
    dfs(0, dig);
    for(int i = 0; i < n; i ++){
        if(!visited[i]) {
            return false;
            //cout << "N0";
        }
    }
    return true;
}

void binsch(long long lo, long long hi){
    while(lo < hi){
        long long mid = (lo + hi)/2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
        cout << lo <<  endl;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> coor[i].first >> coor[i].second;
    }
   
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            dist[i].push_back(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2));
        }
    }
    binsch(0, 1E10);
    /*for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
}