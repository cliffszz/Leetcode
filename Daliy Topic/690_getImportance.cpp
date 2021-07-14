//https://leetcode-cn.com/problems/employee-importance/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    unordered_map<int, int> map;
    int dfs(vector<Employee*>& employees, int id) {
        int sum = 0;
        sum += employees[map[id]]->importance;
        for (int i = 0; i < employees[map[id]]->subordinates.size(); i++) {
            sum += dfs(employees, employees[map[id]]->subordinates[i]);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        for (int i = 0; i < employees.size(); i++) {
            map[employees[i]->id] = i;
        }
        return dfs(employees, id);
    }
};

class Solution2 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < employees.size(); i++) {
            map[employees[i]->id] = i;
        }
        queue<int> que;
        que.push(map[id]);
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            sum += employees[cur]->importance;
            for (int i = 0; i < employees[cur]->subordinates.size(); i++) {
                que.push(map[employees[cur]->subordinates[i]]);
            }
        }
        return sum;
    }
};