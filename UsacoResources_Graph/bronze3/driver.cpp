#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        int n; 
        cin >> n;
        long long A[100000];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        long long cost = 0;
        if(n == 1) {
            cout << "0" << endl;
            continue;
        }
        else if(n==2){
            if(A[0] == A[1]) {
                cout << "0" << endl;
                continue;
            }
            else {
                cout << "-1" << endl;
                continue;
            }
        }
        long long previous[100];
        for(int i=0; i<100;i++){
            previous[i] = 0;
        }
        while(1){
            if(A[0] > A[1] || A[n-1] > A[n-2]) {
                cout << "-1" << endl;
                break;
            }
            int Max = -1, index;
            for(int i = 0; i < n; i++){
                if(Max < A[i]) {
                    Max = A[i];
                    index = i;
                }
            }
            if(index == 0) index = 1;
            else if(index == n - 1) index = n - 2;
            
            if(A[index - 1] + A[index + 1] < A[index]){
                cout << "-1" << endl;
                break;
            }

            long long ans = A[index - 1] + A[index + 1] - A[index]; //6 14 8
            cost = cost + A[index - 1] - ans;
            A[index - 1] = ans;
            cost = cost + A[index] - ans;
            A[index] = ans;
            cost = cost + A[index + 1] - ans;
            A[index + 1] = ans;
            if(*min_element(A, A + n) == *max_element(A, A + n)){
                cout << cost << endl;
                break;
            }
            int check = 0;
            for(int i = 0; i < n; i++){
                if(previous[i] == A[i]) check++;
            }
            if(check == n){
                cout << "-1" << endl;
                break;
            }
            for(int i = 0; i < n; i++){
                previous[i] = A[i];
            }
        }
    }
}