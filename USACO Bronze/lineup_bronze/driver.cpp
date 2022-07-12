#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> cows, beside_a, beside_b;
int n;
int cnt;

void per(){
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 7; i ++){
            if((cows[i] == beside_a[j] && cows[i + 1] == beside_b[j]) || (cows[i + 1] == beside_a[j] && cows[i] == beside_b[j])){
                cnt ++;
            }
        }
    }
}
int main(){
    string a, b, t;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a >> t >> t >> t >> t >> b;
        beside_a.push_back(a);
        beside_b.push_back(b);
    }
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    do{
        cnt = 0;
        per();
        if(cnt/2 == n) {
            for(int i = 0; i < 8; i ++){
            cout << cows[i] << endl;
            }
            break;
        }
    }while(next_permutation(cows.begin(), cows.end()));


}