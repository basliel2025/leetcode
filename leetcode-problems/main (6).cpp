#include <iostream>
#include <vector>
#include<unordered_set>
#include <unordered_map>
using namespace std;
//EVALUATE DIVISION

class Solution {
public:
    unordered_map<string,vector<pair<string, double>>> adjList;
    vector<double>ans;

    bool dfs (string dividend,string divisor,unordered_set<string>vis,double currProd){
       if (vis.find(dividend) != vis.end()){
            return false;
     }
        vis.insert(dividend);
        if (dividend == divisor){
           ans.push_back(currProd);
           return true;
        }
 bool found = false;
    for(auto ne:adjList[dividend]){
           found = dfs(ne.first, divisor,vis, currProd*ne.second);
             if (found){
                return true;
             }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
  int n = equations.size(), m = queries.size();
         adjList.clear();
        ans.clear();
         for (int i = 0;i<n;i++){
            string dividend = equations[i][0];
string divisor = equations[i][1];
      adjList[dividend].push_back({divisor, values[i]});
        adjList[divisor].push_back({dividend,1.0/ values[i]});
         }
     for(auto&q : queries){
            string dividend = q[0];
            string divisor = q[1];
            if (adjList.find (dividend)==adjList.end()|| adjList.find(divisor)==adjList.end()){
             ans.push_back(-1.0);
           }
     else{
                unordered_set<string>vis;
                 if(!dfs(dividend,divisor,vis,1.0)){
                    ans.push_back(-1);
                 }
            }
       }
      return ans;
    }
};