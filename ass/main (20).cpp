#include <iostream>
#include <vector>
#include<map>
#include <set>
#include<queue>
using namespace std;
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, pair<int, int>>> pack;
        map<int, map<int, int>> visited;

        pack.push({0, {1, 0}});

        while (pack.size() ==0 == false) {
            pair<int, pair<int, int>> now = pack.front();
            pack.pop();

            int place = now.first;
            int speed = now.second.first;
            int s = now.second.second;

            if (place == target) {
                return s;
            }

            if (visited.find(place) != visited.end()) {
                if (visited[place].find(speed) != visited[place].end()) {
                    continue;
                }
            }

            visited[place][speed] = 1;

            int Place = place + speed;
            int Speed = speed * 2;
            if (Place < target * 2 && Place > -target * 2) {
                pack.push({Place,{Speed, s + 1}});
            }
            int Sr;
            if (speed > 0) {
                Sr = -1;
            } else {
                Sr = 1;
            }
            if (visited.find(place) == visited.end() || visited[place].find(Sr) == visited[place].end()) {
                pack.push({place,{Sr, s + 1}});
            }
        }

        return -1;

    }
};