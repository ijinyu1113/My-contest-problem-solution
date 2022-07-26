#include <iostream>
#include <vector>
using namespace std;

vector<int> used;

char hexa[7][6];
int order;
int success = 0;

//rotate so that index comes to goal position

void rotate(int num, int index, int goal){
        char temp[6];
        
        for(int j = 0; j < 6; j++){
            temp[j] = hexa[num][j];
        }
        for(int j = 0; j < 6; j++){
            int a = goal+j;
            if(a >= 6) a-= 6;
            
            hexa[num][a] = temp[index];
            
            index++;
            if(index >= 6){
                index = 0;
            }
        }
        
}

void find(int main, int main_index, int now_index){
    for(int i = 0; i < 7; i++){
        int flag = 0;
        for(int j = 0; j < used.size(); j++){
            if(i == used[j]) flag = 1;
        }
        if(flag == 1) continue;
        
        for(int j = 0; j < 6; j++){
            if(hexa[main][main_index] == hexa[i][j]){
                rotate(i, j, now_index);
                if(order == 1){
                    order++;
                    used.push_back(i);
                    main_index++; now_index++;
                    if(now_index == 6) now_index = 0;
                    find(main, main_index, now_index);
                    order--;
                    used.pop_back();
                    main_index--; now_index--;
                    if(now_index == -1) now_index = 5;
                }
                else{
                    int a = now_index+1;
                    int b = now_index-2;
                    
                    if(a == 6) a = 0;
                    if(b < 0) b = 6 + b;
                    if(hexa[i][a] == hexa[used.back()][b]){
                        if(order < 6){    
                            order++;
                            used.push_back(i);
                            main_index++; now_index++;
                            if(now_index == 6) now_index = 0;
                            find(main, main_index, now_index);
                            order--;
                            used.pop_back();
                            main_index--; now_index--;
                            if(now_index == -1) now_index = 5;
                        }
                        else{
                            // last hexagaon
                            if(hexa[i][1] == hexa[used[1]][4]){
                                used.push_back(i);
                                success = 1;
                                return;
                            }
                        }
                    }
                    else{
                        //undo rotate
                        rotate(i, now_index, j);
                    }
                }    
                break;
            }
        }
    }
    
}

int main() {
    int n;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++){
            cin >> hexa[i][j];
        }
    }
        
    for(int i = 0; i < 7; i++){
        used.push_back(i);
        
        char min = 'Z';
        int index = 0;
        char temp[6];
        
        //find alphabetically smallest letter
        for(int j = 0; j < 6; j++){
            if(min > hexa[i][j]) {
                min = hexa[i][j];
                index = j;
            }
        }
        //rotate so that index comes to 0 position
        rotate(i, index, 0);
        
        order = 1;
        find(i, 0, 3);
        if(success == 1){
            int order[7] = {5, 6, 4, 0, 1, 3, 2};
            for(int j = 0; j < 7; j++){
                cout << used[order[j]] << hexa[used[order[j]]][0] << " ";
            }
            return 0;
        }
        used.clear();
    }
    
    return 0;
}