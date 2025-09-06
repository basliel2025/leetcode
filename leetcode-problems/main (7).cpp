#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    vector<pair<int , int>> position = { {1,0} ,{0,1},{1,1},{1,-1},{-1,1},{-1,0},{0,-1},{-1,-1}};
    if(grid[grid.size()-1] [grid[0].size() -1] != 0 || grid[0][0] !=0 ){
        return -1;
    }
    queue<pair<int , int>> find;
    find.push({0,0});
    grid[0][0] =1; // we do this because for every point in our search we will update the next spot with the path value plus one(it is useful to store the values and to compute the distance)
    while(find.size()> 0){
        pair<int , int> coordinates = find.front();
        find.pop();
        int row = coordinates.first;
        int column = coordinates.second;
        int distance = grid[row][column];
        if(row == grid.size()-1 && column == grid[0].size()-1){
            return distance;
        }
        int x = 0;
        while(x< position.size()){
            int row_distance = position[x].first;
            int column_distance = position[x].second;
            int newRow = row_distance + row;
            int newColumn = column_distance + column;
            if ((grid.size() > newRow && newRow >= 0) && (grid[0].size() > newColumn && newColumn >= 0) && (grid[newRow][newColumn] == 0)){
                find.push({newRow, newColumn});
                grid[newRow][newColumn] = distance + 1;
            }
            x= x+1;
        }
    }
    return -1;
};

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.