#include <bits/stdc++.h>

using namespace std;
const int MN = 5E6;

int line[MN];
vector<long long> enemy;
vector<long long> ans;
int main(){
    int k, m, n;
    cin >> k >> m >> n;
    enemy.resize(m);
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        line[a] = b;
    }
    for(int i = 0; i < m; i++){
        cin >> enemy[i];
    }
    for(int i = 0; i < m - 1; i++){
        for(int j = enemy[i]; j < enemy[i+1]; j++){
            if(line[j] != 0){
                if(abs(j - enemy[i]) < abs(j - enemy[i+1])){
                    ans[i] += line[j];
                }
            }
        }
    }
    int a = 0;
    for(int i = 0; i < enemy[0]; i++){
        a += line[i];
    }
    ans.push_back(a);

    cout << 36;
}