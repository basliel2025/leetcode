#include <iostream>
#include <vector>
#include<queue>
#include<set>
#include <stack>
using namespace std;
int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> side(isConnected.size());
    int x= 0;
    while(x< isConnected.size()){
        int y=0;
        while(y<isConnected.size()){
            if(isConnected[x][y]){
                side[x].push_back(y);
                side[y].push_back(x);
            }
            y = y+1;
        }
        x= x+1;
    }
    vector<int> seen(isConnected.size(), 0);
    int see = 0;
    int s =0;
    while(s<isConnected.size()){
        if(seen[s] == 0){
            stack<int> collection;
            collection.push(s);
            seen[s]= 1;
            while(collection.size()> 0){
                int city = collection.top();
                collection.pop();
                int point =0;
                while(point < side[city].size()){
                    if(seen[side[city][point]] == 0){
                        seen[side[city][point]]= 1;
                        collection.push(side[city][point]);
                    }
                    point = point +1;
                }
            }
            see = see+1;
        }
        s = s+1;
    }
    return see;
};
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.