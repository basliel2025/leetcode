#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int , int>> container;
    vector<vector<int>> got (mat.size(), vector<int> (mat[0].size(),-1));
    int ms = mat.size();
    int mz = mat[0].size();
    int x =0;
    while(x< ms){
        int y = 0;
        while(y < mz){
            if(mat[x][y]==0){
                container.push({x,y});
                got[x][y]=0;
            }
            y++;
        }
        x++;
    }
    vector<pair<int , int>> position = { {0,1},{1,0},{-1,0},{0,-1}};
    while(container.size()>0){
        int x = container.front().first;
        int y = container.front().second;
        container.pop();
        int a =0;
        int p = position.size();
        while(a<p){
            int newX = x + position[a].first;
            int newY = y + position[a].second;
            if(newX >=0 && newX < ms && newY >=0 && newY < mz && got[newX][newY] ==-1){
                container.push({newX, newY});
                got[newX][newY] = got[x][y] +1;
            }
            a= a+1;
        }
    }
    return got;
};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.