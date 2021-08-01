//https://leetcode-cn.com/problems/queue-reconstruction-by-height/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size());
        for (vector<int>& p : people) {
            int space = p[1] + 1;
            for (int i = 0; i < people.size(); i++) {
                if (res[i].empty()) {
                    space--;
                    if (space == 0) {
                        res[i] = p;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (vector<int>& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};