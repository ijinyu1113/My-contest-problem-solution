#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
vector<pair<int, int>> g[MAXN];
vector<int> ar(MAXN);
vector<int> visited(MAXN);
int n, m;

void dfs(int node, long long minmax, int label){
    if(visited[node] != 0) return;
    visited[node] = label;

    for(auto u: g[node]){
        //cout << u.second << " " << minmax << endl;
        if(u.second >= minmax){
            //cout << "yes";
            dfs(u.first, minmax, label);
        }
    }
}

bool check(long long p){
    
    fill(visited.begin(), visited.end(), 0);
    int label = 1;
    for(int i = 0; i < n; i ++){
        if(visited[i] == 0){
            dfs(i, p, label++);
        }
    }
    for(int i = 0; i < n; i++){
            for(int j = 0; j<n;j++){
                //cout << visited[j] << " ";
            }
            //cout << endl;
        if(ar[i] != i){
            if(visited[ar[i]] != visited[i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    
    cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(ar[i] == i) cnt++;
    }
    
    if(cnt == n) {
        cout <<"-1";
        return 0;
    }

	long long lo = 1, hi = 1e9 + 1;
    long long sol = -1;
	while(lo <= hi){
        long long mid = (hi + lo)/2;
        //cout << mid << " ";
        if(check(mid)){
            lo = mid + 1;
            sol = max(sol, mid);
            //cout << hi << " ";
            
        }
        else{
            hi = mid - 1;
            //cout << "0 ";
        }
    }
    cout << sol <<  endl;

}