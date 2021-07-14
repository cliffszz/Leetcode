//https://leetcode-cn.com/problems/daily-temperatures/
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int pre = stk.top();
                res[pre] = i - pre;
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};