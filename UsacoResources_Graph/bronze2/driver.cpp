#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int z = 0; z < t; z++){
        int a[4], b[4];
        int flag = 0;
        for(int i = 0; i < 4; i++){
            cin >> a[i];
        }
        for(int i = 0; i < 4; i++){
            cin >> b[i];
        }
        int c[4];
        int win = 0, loss = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(a[i] > b[j]) win++;
                if(a[i] < b[j]) loss++;
            }
        }
        if(win > loss){
            for(int i = 1; i <= 10; i++){
                for(int j = 1; j <= 10; j++){
                    for(int k = 1; k <= 10; k++){
                        for(int l = 1; l <= 10; l++){
                            c[0] = i; c[1] = j; c[2] = k; c[3] = l;
                            int win1 = 0, loss1 = 0;
                            for(int x = 0; x < 4; x++){
                                for(int y = 0; y < 4; y++){
                                    if(c[x] > a[y]) win1++;
                                    if(c[x] < a[y]) loss1++;
                                }
                            }
                            int win2 = 0, loss2 = 0;
                            for(int x = 0; x < 4; x++){
                                for(int y = 0; y < 4; y++){
                                    if(c[x] > b[y]) win2++;
                                    if(c[x] < b[y]) loss2++;
                                }
                            }
                            if(win1 > loss1 && win2 < loss2){
                                flag = 1; 
                            }
                        }
                    }
                }
            }
            if(flag == 1) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else if(win < loss){
            for(int i = 1; i <= 10; i++){
                for(int j = 1; j <= 10; j++){
                    for(int k = 1; k <= 10; k++){
                        for(int l = 1; l <= 10; l++){
                            c[0] = i; c[1] = j; c[2] = k; c[3] = l;
                            int win1 = 0, loss1 = 0;
                            for(int x = 0; x < 4; x++){
                                for(int y = 0; y < 4; y++){
                                    if(c[x] > b[y]) win1++;
                                    if(c[x] < b[y]) loss1++;
                                }
                            }
                            int win2 = 0, loss2 = 0;
                            for(int x = 0; x < 4; x++){
                                for(int y = 0; y < 4; y++){
                                    if(c[x] > a[y]) win2++;
                                    if(c[x] < a[y]) loss2++;
                                }
                            }
                            if(win1 > loss1 && win2 < loss2){
                                flag = 1;
                            }
                        }
                    }
                }
            }
            if(flag == 1) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}