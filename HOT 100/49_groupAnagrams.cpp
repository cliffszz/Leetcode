//https://leetcode-cn.com/problems/group-anagrams/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            map[k].push_back(s);
        }
        vector<vector<string>> res;
        return res;
        for (auto it = map.begin(); it != map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};