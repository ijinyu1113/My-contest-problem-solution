#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
//<pair<long, long>> interval;
int low[25000000];
int high[25000000];
vector<int> psum;

int main(){
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(n);
    psum.resize(2*m+5);
    //interval.resize(25000000);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int cnt=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //interval.push_back(make_pair(a[i] + a[j], b[i] + b[j]));
            low[cnt] = a[i]+a[j];
            high[cnt] = b[i]+b[j];
            cnt++;
        }
    }
    
    for(int i = 0; i < n*n; i++){
        //psum[interval[i].first]++;
        //psum[interval[i].second + 1]--;
        psum[low[i]]++;
        psum[high[i]+1]--;
    }
    for(int i = 0; i < 2*m+1; i++){
        psum[i + 1] += psum[i];
    }
    for(int i = 0; i < 2*m+1; i++){
        cout << psum[i] << endl;
    }
    
    //cout << "0\n0\n1\n3\n4\n4\n4\n3\n3\n1\n1\n";
}