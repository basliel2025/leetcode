#include <iostream>
#include <vector>
#include<set>
#include <stack>
using namespace std;
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int output =0;
    int row = grid.size();
    int column = grid[0].size();
    int x=0;
    while(x<row){
        int y=0;
        while(y<column){
            if(grid[x][y]==1){
                int area =0;
                stack<pair<int , int>> ele;
                ele.push({x,y});
                grid[x][y]=2;
                while(ele.size()>0){
                    int a = ele.top().first;
                    int b = ele.top().second;
                    ele.pop();
                    area += 1;
                    int p[4]= {1,-1,0,0};
                    int q[4]= {0,0,1,-1};
                    int position = 0;
                    while(position < 4){
                        int f = p[position] + a;
                        int g = q[position] + b;
                        position +=1;
                        if(f>=0 && f< row && g >=0 && g< column && grid[f][g] == 1){
                            ele.push({f,g});
                            grid[f][g]=2;
                        }
                    }
                }
                output = max(output, area);
            }
            y= y+1;
        }
        x = x+1;
    }
    return output;
};// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.