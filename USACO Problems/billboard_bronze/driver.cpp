#include<iostream>

using namespace std;
int x1[3], y1[3], x2[3], y2[3];

int area(int x1, int y1, int x2, int y2){
    return (x2-x1) * (y2-y1);
}

int overlap(int n){
    int x, y;
    x = max(0, min(x2[n], x2[2]) - max(x1[n], x1[2]));
    y = max(0, min(y2[n], y2[2]) - max(y1[n], y1[2]));
    return x * y;
}

int main(){

    for(int i = 0; i < 3; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    cout << area(x1[0], y1[0], x2[0], y2[0]) + area(x1[1], y1[1], x2[1], y2[1]) - overlap(0) - overlap(1) << endl;
}