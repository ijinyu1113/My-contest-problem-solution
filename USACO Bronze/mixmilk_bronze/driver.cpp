#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int c[3];
    int m[3];
    int r = 0;
    int t;
    for(int i = 0; i < 3; i ++){
        cin >> c[i] >> m[i];
    }

    for(int i = 0; i < 100; i ++){
        r = i % 3; 
        if(r == 2){
            t = min(m[2], c[0] - m[0]);
			m[2] -= t;
            m[0] += t;
        }
        else{
            t = min(m[r], c[r + 1] - m[r + 1]);
			m[r] -= t;
            m[r + 1] += t;
        }
        cout << m[r] << endl;
    }
    cout << m[0] << endl << m[1] << endl << m[2] << endl;
}