#include <iostream>
#include <vector>
#include<set>
#include <stack>
#include<queue>
using namespace std;
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    vector<vector<int>> position = {{1,0},{1,1},{1,-1},{0,1},{0,-1},{0,0},{-1,-1},{-1,0},{-1,1}};
    int rc = click[0];
    int cc = click[1];
    int ms =0;
    int x=0;
    while(x< position.size()){
        int r = rc + position[x][0];
        int c = cc + position[x][1];
        if(r>=0 && r<board.size() && c>=0 && c< board[0].size() && board[r][c] == 'M'){
            ms+=1;
        }
        x+=1;
    }
    if (board[rc][cc] == 'M'){
        board[rc][cc] = 'X';
    }
    else if( ms>0){
        board[rc][cc] = '0' + ms;
    }
    else{
        board[rc][cc]= 'B';
        int a =0;
        while(a< position.size()){
            int r = rc + position[a][0];
            int c = cc + position[a][1];
            if(r>=0 && r< board.size() && c>=0 && c< board[0].size() && board[r][c] == 'E'){
                vector<int> Continue = {r,c};
                board = updateBoard(board, Continue);
            }
            a+=1;
        }
    }
    return board;
};