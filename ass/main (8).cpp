#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
int openLock(vector<string>& deadends, string target) {
    set<string>dead (deadends.begin(), deadends.end());
    queue<pair<string , int>> Dead;
    set<string> seen;
    if(dead.find("0000") == dead.end()){
        Dead.push({"0000", 0});
        seen.insert("0000");
    }
    while(Dead.size()> 0){
        pair<string, int> present = Dead.front();
        Dead.pop();
        string f = present.first;
        int count = present.second;
        if(f== target){
            return count;
        }
        int x = 0;
        while(x < 4){
            string tempA;
            string tempB;
            tempA = f.substr(0,x) + to_string((f[x] - '0'+ 1)%10) + f.substr(x+1);
            tempB = f.substr(0,x) + to_string((f[x]- '0' + 9) % 10) + f.substr(x+1);
            if(dead.find(tempA)== dead.end() && seen.find(tempA) == seen.end()){
                Dead.push({tempA, count +1});
                seen.insert(tempA);
            }
            if(dead.find(tempB) == dead.end() && seen.find(tempB)== seen.end()){
                Dead.push({tempB, count +1});
                seen.insert(tempB);
            }
            x = x+1;
        }

    }
    return -1;
};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.