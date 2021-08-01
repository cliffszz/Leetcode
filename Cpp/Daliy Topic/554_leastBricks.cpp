//https://leetcode-cn.com/problems/brick-wall/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> map;
        for (auto& widths : wall) {
            int sum = 0;
            for (int i = 0; i < widths.size() - 1; i++) {
                sum += widths[i];
                map[sum]++;
            }
        }
        int maxCnt = 0;
        for (auto it = map.begin(); it != map.end(); it++) {
            maxCnt = max(maxCnt, it->second);
        }
        return wall.size() - maxCnt;
    }
};