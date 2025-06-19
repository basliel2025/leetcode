#include <iostream>
#include <vector>
#include<set>
#include <stack>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> g = grid;
    int fresh = 0;
    queue<pair<int , int>> pack;
    for(int i=0;i< grid.size(); i++){
        for(int j=0; j< grid[0].size();j++){
            if(grid[i][j] ==2){
                pack.push({i,j});

            }
            else if(grid[i][j]==1){
                fresh = fresh +1;
            }
        }
    }
    int time = -1;

    while(pack.size()>0){
        int s= pack.size();
        for(int a =0; a<s; a++){
            auto [i,j]= pack.front();
            pack.pop();
            if(i+1<grid.size() && g [i+1][j] ==1){
                g[i+1][j] =2;
                fresh--;
                pack.push({i+1,j});

            }
            if(i-1>=0 && g [i-1][j] ==1){
                g[i-1][j] =2;
                fresh--;
                pack.push({i-1,j});

            }
            if(j+1<grid[0].size() && g [i][j+1] ==1){
                g[i][j+1] =2;
                fresh--;
                pack.push({i,j+1});

            }
            if(j-1>=0 && g [i][j-1] ==1){
                g[i][j-1] =2;
                fresh--;
                pack.push({i,j-1});

            }
        }
        time++;
    }
    if(fresh>0){
        return -1;
    }
    if(time ==-1 ){
        return 0;
    }
    return time;

};