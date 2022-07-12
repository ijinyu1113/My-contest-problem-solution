#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

vector<int> adj[100];

bool visited[100];
int invited;

void DFS(int curFriend, int friend1, int friend2){
	if(visited[curFriend]){
		return;
	}
	visited[curFriend] = true;
	++invited;
	for(int invitedFriend: adj[curFriend]){
		if((curFriend == friend1 && invitedFriend == friend2) || (invitedFriend == friend1 && curFriend == friend2)){
			continue;
		}
		DFS(invitedFriend, friend1, friend2);
	}
}

int main(){
	for(int i=0; i<10; i++){
		int p, c; cin >> p >> c;
		if(p == 0 && c == 0){
			break;
		} else {
			for(int i=0; i<p; i++){
				adj[i].clear();
			}
			vector<pi> connection;
			for(int i=0; i<c; i++){
				int a, b; cin >> a >> b;
				connection.push_back({a, b});
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			bool allInvited = true;
			for(int i=0; i<c; i++){
				fill(visited, visited + p, false);
				invited = 0;
				DFS(0, connection[i].first, connection[i].second);
				if(invited < p){
					allInvited = false;
				}
			}
			if(allInvited){
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		}
	}
}