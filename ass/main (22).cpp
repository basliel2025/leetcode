#include <iostream>
#include <vector>
#include<set>
#include <stack>
#include<queue>
using namespace std;
int snakesAndLadders(vector<vector<int>>& board) {
    int s = board.size();
    int boardsize = s*s;
    vector<int> box (boardsize +1, -1);
    int place =1;
    bool left = true;
    int row = s-1;
    while(row>=0){
        int x =0;
        while(x<s){
            int column ;
            if(left != false){
                column =x;
            }
            else{
                column = s-x-1;
            }
            box[place]= board[row][column];
            place++;
            x++;
        }
        left = !left;
        row--;
    }
    queue<int> pack;
    vector<int> seen(boardsize +1 , 0);
    pack.push(1);
    seen[1] = 1;
    int go = 0;
    while(pack.size()>0){
        int sz = pack.size();
        int i=0;
        while(i<sz){
            int now = pack.front();
            pack.pop();
            if (now == boardsize){
                return go;
            }
            int roll =1;
            while(roll<=6){
                int coming = now + roll;
                if(coming <= boardsize){
                    int finals;
                    if(box[coming] != -1){
                        finals = box[coming];
                    }
                    else{
                        finals = coming;
                    }
                    if(seen[finals] == 0){
                        seen[finals]= 1;
                        pack.push(finals);
                    }
                }
                roll++;
            }
            i++;
        }
        go++;
    }
    return -1;
};