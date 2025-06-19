#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int a = isWater.size();
    int b = isWater[0].size();
    vector<vector<int>>grid(a,vector<int>(b,INT_MAX));
    queue<pair<int, int>> container;
    int x =0;
    while(x<a){
        int y=0;
        while(y<b){
            if(isWater[x][y] ==1){
                container.push({x,y});
                grid[x][y]=0;
            }
            y++;
        }
        x++;
    }
    while(container.size()>0){
        int c = container.front().first;
        int d = container.front().second;
        container.pop();
        int pc [4]= {0,0,-1,1};
        int pd [4]= {-1,1,0,0};
        int i = 0;
        while(i<4){
            int f = c+pc[i];
            int g = d+ pd[i];
            if(f>=0 && f<a && g>=0 && g<b && grid[f][g]> 1+ grid[c][d]){
                grid[f][g]= grid[c][d] +1;
                container.push({f,g});
            }
            i++;
        }
    }
    return grid;
};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.