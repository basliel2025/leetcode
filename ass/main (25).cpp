#include <iostream>
#include <vector>
#include<map>
#include <stack>
#include<queue>
using namespace std;
#include <iostream>
#include <vector>
#include<map>
#include <stack>
#include<queue>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row [4]= {1,-1,0,0};
        int column [4] = {0,0,-1,1};
        stack<pair<int, int>> collection;
        int x= 0;
        while(x< board.size()){
            int y=0;
            while(y< board[0].size()){
                if (board[x][y] == 'O' && (x==0 || x== board.size()-1 || y==0 || y== board[0].size()-1)){
                    collection.push({x,y});
                    while(collection.size()>0){
                        int X = collection.top().first;
                        int Y = collection.top().second;
                        collection.pop();
                        if(board[X][Y] == 'O'){
                            board[X][Y] = 'Z';
                            int v =0;
                            while(4>v){
                                int i = X + row[v];
                                int j = Y + column[v];
                                if(i>=0 && i< board.size()&& j>=0 && j< board[0].size()){
                                    collection.push({i,j});
                                }
                                v+=1;
                            }
                        }
                    }
                }
                y+=1;
            }
            x+=1;
        }
        int a =0;
        while(a< board.size()){
            int b =0;
            while(b < board[0].size()){
                if(board[a][b] == 'O'){
                    board[a][b] = 'X';
                }
                else if(board[a][b] == 'Z'){
                    board[a][b] = 'O';
                }
                b+=1;
            }
            a+=1;
        }

    }
};
