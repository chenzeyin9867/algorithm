#include "head.h"

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeFile;
        for(auto e : employees){
            employeeFile[e->id] = e;
        }
        Employee * employee = employeeFile[id], *cur = employee;
        queue<Employee*> q;
        q.push(cur);
        int importanceScore = 0;
        while(!q.empty()){
            cur = q.front();
            importanceScore += cur->importance;
            q.pop();
            if(cur->subordinates.size() > 0){
                for(auto subOrd: cur->subordinates){
                    q.push(employeeFile[subOrd]);
                }
            }
        }
        return importanceScore;
    }
};