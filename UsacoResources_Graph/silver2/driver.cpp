#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;

int n, m;
vector<int> adj[MAXN];
vector<int> visited(MAXN);
vector<int> visited1(MAXN);
vector<int> visited2(MAXN);
vector<int> a;
vector<int> b;
vector<int> c;

void dfs1(int node){
    visited1[node] = 1;
    visited[node] = 1;
	for(int u: adj[node])
		if(visited1[u] == 0)
			dfs1(u);
}

void dfs2(int node){
    visited2[node] = 1;
	visited[node] = 1;
    for(int u: adj[node])
		if(visited2[u] == 0)
			dfs2(u);
}

void dfs3(int node){
    visited[node] = 1;
    c.push_back(node);
    for(int u: adj[node]){
        if(!visited[u])
        dfs3(u);
    }
}

vector<long long> realans;

int main(){
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        cin >> n >> m;
        int x, y;
        for(int i = 0; i < m; i ++){
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs1(0);
        dfs2(n-1);
        
        for(int i = 0; i < n; i++){
            if(visited1[i] == 1) a.push_back(i);
            if(visited2[i] == 1) b.push_back(i);
        }
        if(a.size() == 0) a.push_back(0);
        if(b.size() == 0) b.push_back(n-1);
        long long ans1 = 1E10;
        long long ans2 = 1E10;
        long long ans3 = 1E10;
        long long ans = 1E10;
        for(int i = 0; i < n; i++){
            if(visited[i] == 0) {
                c.clear();
                dfs3(i); 
                if(c.size() == 1) continue;
                for(int j = 0; j < c.size(); j++){
                    int lo = 0;
                    int hi = a.size()-1;
                    while (lo < hi) {
                        int mid = (lo + hi) / 2;
                        if(c[j] <= a[mid]) hi = mid;
                        else lo = mid + 1;
                    }
                    if(lo < a.size()-1){
                        if(abs(c[j] - a[lo]) > abs(c[j] - a[lo + 1])){
                            lo = lo + 1;
                        } 
                    }
                    if(lo > 0){
                        if(abs(c[j] - a[lo]) > abs(c[j] - a[lo - 1])){
                            lo = lo - 1;
                        }
                    }
                    ans1 = min(ans1, (long long)(abs(c[j] - a[lo])));
                    lo = 0;
                    hi = b.size()-1;
                    while (lo < hi) {
                        int mid = (lo + hi) / 2;
                        if(c[j] <= b[mid]) hi = mid;
                        else lo = mid + 1;
                    }
                    if(lo < b.size()-1){
                        if(abs(c[j] - b[lo]) > abs(c[j] - b[lo + 1])){
                            lo = lo + 1;
                        } 
                    }
                    if(lo > 0){
                        if(abs(c[j] - b[lo]) > abs(c[j] - b[lo - 1])){
                            lo = lo - 1;
                        }
                    }
                    ans2 = min(ans2, (long long)(abs(c[j] - b[lo])));
                }
                ans = min(ans, ans1*ans1 + ans2 * ans2);
            }
            //cout << ans << endl;
        }/*
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;
        */
        for(int i = 0; i < a.size(); i++){
            int lo = 0;
            int hi = b.size()-1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if(a[i] <= b[mid]) hi = mid;
                else lo = mid + 1;
            }
            if(lo < b.size()-1){
                if(abs(a[i] - b[lo]) > abs(a[i] - b[lo + 1])){
                    lo = lo + 1;
                } 
            }
            if(lo > 0){
                if(abs(a[i] - b[lo]) > abs(a[i] - b[lo - 1])){
                    lo = lo -1;
                }
            }
            ans3 = min(ans3, (long long) abs(a[i] - b[lo]));
        }

        if(ans3%2 == 0) ans3 = (ans3/2) * (ans3/2) + (ans3/2) * (ans3/2);
        else ans3 = (ans3/2) * (ans3/2) + (ans3/2 + 1) * (ans3/2 + 1);
        //cout << ans3 << endl;
        ans = min(ans, ans3);
        cout << ans << endl;        
        fill(visited.begin(), visited.end(), 0);
        fill(visited1.begin(), visited1.end(), 0);
        fill(visited2.begin(), visited2.end(), 0);
        for(int i = 0; i < MAXN; i++){
            adj[i].clear();
        }
        a.clear();
        b.clear();
    }
}