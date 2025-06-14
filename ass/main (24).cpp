#include <iostream>
#include <vector>
#include<map>
#include <set>
#include<queue>
using namespace std;
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int, int>> path;
    int way =0;
    vector<vector<int>> possibilities = {{1,0},{0,1},{-1,0},{0,-1}};
    path.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';
    while(path.size()>0){
        int x = path.size();
        while(x>0){
            pair<int, int> now = path.front();
            path.pop();
            int f = now.first;
            int s = now.second;
            int k=0;
            while(4>k){
                int a = f + possibilities[k][0];
                int b = s + possibilities[k][1];

                if(a>=0 && b>=0 && a< maze.size() && b< maze[0].size() && maze[a][b]== '.' ){
                    if((a==0&&  b==0 && a==maze.size()-1 || b==maze[0].size()-1) &&
                  !(a == entrance[0] && b == entrance[1])){


                        return way +1 ;
                  }


                    maze[a][b]= '+';
                    path.push({a,b});
                }
                k+=1;
            }

            x-=1;
        }

        way+=1;
    }
    return -1;
};