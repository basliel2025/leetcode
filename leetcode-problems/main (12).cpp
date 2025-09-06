#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
int maxDistance(vector<vector<int>>& grid) {
    int row = grid.size();
    int column = grid[0].size();
    queue<pair<int, int>> container;
    int x =0;
    while(x<row){
        int y =0;
        while(y<column){
            if(grid[x][y]==1){
                container.push({x,y});
                grid[x][y]=2;
            }
            y++;
        }
        x++;
    }
    if(container.size() ==0 || container.size()==row * column){
        return -1;
    }
    int dmax = 0;
    int h[4]= {-1,1,0,0};
    int v[4] = {0,0,-1,1};
    while(container.size()>0){
        int s = container.size();
        while(s--){
            auto node = container.front();
            container.pop();
            int f = node.first;
            int sec = node.second;
            int a=0;
            while(a<4){
                int nh = f + h[a];
                int nv = sec + v[a];
                if(nh>=0 && nh<row && nv>=0 && nv < column && grid[nh][nv]==0){
                    grid[nh][nv] = grid[f][sec] +1;
                    dmax = max(dmax, grid[nh][nv]-2);
                    container.push({nh,nv});
                }
                a++;
            }
        }
    }
    return dmax;
};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.