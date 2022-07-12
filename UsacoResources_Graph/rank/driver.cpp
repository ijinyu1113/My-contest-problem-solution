#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
vector<int> win[MAXN];
int n, k;
int start;
vector<bool> record(25);
vector<int> answer;
bool check = false;
bool succeed = false;

void dfs(int p){
    if(p == start && check == false) check = true;
    else if(p == start && check == true){
        succeed = true;
        return;
    } 
    
    if(record[p]){
        return;
    }
    
    record[p] = true;
    
    for(int u: win[p]){
        dfs(u);
    }

    //return;
}

int main(){
     cin >> n >> k;
     int a, b, s_a, s_b;
     for(int i = 0; i < k; i ++){
         cin >> a >> b >> s_a >> s_b;
         if(s_a > s_b){
             win[a].push_back(b);
         }
         else{
             win[b].push_back(a);
         }
     }
    for(int i = 1; i <= n; i ++){
        start = i; check = false; succeed = false;
        dfs(start);
        if(succeed == true) {    
            answer.push_back(start);
        }
        fill(record.begin(), record.end(), false);
    }
        cout << answer.size() << endl;
}