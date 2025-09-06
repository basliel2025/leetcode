#include <iostream>
#include <vector>
#include<set>
#include <stack>
#include<queue>
using namespace std;
int maximumDetonation(vector<vector<int>>& bombs) {
    vector<vector<int>> side(bombs.size());
    int x =0;
    while(x< bombs.size()){
        long long rad= bombs[x][2];
        long long xcor = bombs[x][0];
        long long ycor = bombs[x][1];
        int y =0;
        while(y< bombs.size()){
            if(x != y ){
                long long Xcor = bombs[y][0];
                long long Ycor = bombs[y][1];
                long long  Rad = bombs[y][2];
                long long dt = (xcor- Xcor) * (xcor- Xcor) + (ycor- Ycor)* (ycor- Ycor);
                if(rad*rad >= dt){
                    side[x].push_back(y);
                }
            }
            y+=1;
        }
        x+=1;
    }
    int output = 0;
    int p =0;
    while(p < bombs.size()){
        vector<int> seen(bombs.size(), 0);
        queue<int> collection;
        collection.push(p);
        seen[p] = 1;
        int see = 1;
        while(collection.size()>0){
            int now = collection.front();
            collection.pop();
            int q =0;
            while(q<side[now].size()){
                int after = side[now][q];
                if(seen[after]==0){
                    seen[after]= 1;
                    collection.push(after);
                    see+=1;
                }
                q+=1;
            }
        }
        output = max(output , see);
        p+=1;
    }
    return output;

};