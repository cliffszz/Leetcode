//https://leetcode-cn.com/problems/task-scheduler/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        vector<int> vec(26, 0);
        for (char& c : tasks) {
            vec[c - 'A']++;
        }
        sort(vec.begin(), vec.end(), [](int& x, int& y) { return x > y; });
        int cnt = 1;
        while (cnt < vec.size() && vec[cnt] == vec[0]) {
            cnt++;
        }
        return max(s, cnt + (n + 1) * (vec[0] - 1));
    }
};