#include <iostream>
#include <vector>
#include<set>
#include <stack>
#include<queue>
using namespace std;
class Solution {
public:
    int id;
    int importance;
    vector<int> subordinates;
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> emp;
        int sum =0;
        emp.push(id);
        while(emp.size()>0){
            int empID = emp.front();
            emp.pop();
            int x=0;
            while(x<employees.size()){
                if(employees[x] -> id == empID){
                    sum= sum + employees[x]-> importance;
                    int y =0;
                    while(y< employees[x]->subordinates.size()){
                        emp.push(employees[x]->subordinates[y]);
                        y = y+1;
                    }
                }
                x= x+1;
            }
        }
        return sum;
    }
};