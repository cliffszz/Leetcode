//https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> res;
    int len = 0;
    void backTracking(string s, int id) {
        if (id == len - 1) {
            res.push_back(s);
            return;
        }
        set<int> set;
        for (int i = id; i < len; i++) {
            if (set.find(s[i]) != set.end()) continue;
            set.insert(s[i]);
            swap(s[i], s[id]);
            backTracking(s, id + 1);
            swap(s[i], s[id]);
        }
    }

    vector<string> permutation(string s) {
        len = s.size();
        backTracking(s, 0);
        return res;
    }
};