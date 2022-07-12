#include <bits/stdc++.h>

using namespace std;

int main(){
    char answer[3][3];
    char guess[3][3];
    
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 3; j++){
            answer[i][j] = s[j];
        }
    }

    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 3; j++){
            guess[i][j] = s[j];
        }
    }
    int ans1 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(answer[i][j] == guess[i][j]){
                ans1++;
                answer[i][j] = '0';
                guess[i][j] = '0';
            }
        }
    }
    int ans2 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(guess[i][j] == '0') continue;
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(answer[k][l] == '0') continue;
                    if(guess[i][j] == answer[k][l]) {
                        ans2++;
                        guess[i][j] = '0';
                        answer[k][l] = '0';
                    }
                }
            }
        }
    }
    cout << ans1 << endl << ans2 << endl;
}