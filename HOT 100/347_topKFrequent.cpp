//https://leetcode-cn.com/problems/top-k-frequent-elements/
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }
        vector<pair<int, int>> vec;
        for (auto it = map.begin(); it != map.end(); it++) {
            vec.push_back({it->first, it->second});
        }
        sort(vec.begin(), vec.end(), compare);
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = vec[i].first;
        }
        return res;
    }
};

class Solution2 {
public:
    //仿函数的写法
    struct cmp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int& n : nums) {
            map[n]++;
        }
        //priority_queue<Type, Container, Functional>
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        for (auto& m : map) {
            int num = m.first;
            int cnt = m.second;
            if (que.size() == k) {
                if (que.top().second < cnt) {
                    que.pop();
                    que.emplace(num, cnt);
                }
            } else {
                que.emplace(num, cnt);
            }
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};