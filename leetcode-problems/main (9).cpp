#include <iostream>
#include <vector>
#include<queue>
#include<set>
using namespace std;
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    set<int> visited;
    queue<int> collection;
    collection.push(0);
    while(collection.size()>0){
        int x = 0;
        while(x < collection.size()){
            int present = collection.front();
            collection.pop();
            visited.insert(present);
            vector<int> keys = rooms[present];
            int y = 0;
            while(y < keys.size()){
                if (visited.find(keys[y]) == visited.end()){
                    collection.push(keys[y]);
                }
                y = y+1;
            }
        }
    }
    if(visited.size()== rooms.size()){
        return 1;
    }
    else{
        return 0;
    }

};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.