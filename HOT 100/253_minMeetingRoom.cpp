//https://leetcode-cn.com/problems/meeting-rooms-ii/
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> map;
        for(auto& i : intervals){
            map[i[0]]++;
            map[i[1]]--;
        }
        int res = 0, sum = 0;
        for(auto& m : map){
            sum += m.second;
            res = max(res, sum);
        }
        return res;
    }
};

class Solution2 {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ret = 0, cur = 0;
        set<int> set;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size(); ++i) {
            if(!set.empty()) {
                for(auto it = set.begin(); it != set.end(); ++it) {
                    if(*it <= intervals[i][0]) {
                        --cur;
                        set.erase(it);
                    }
                }
            }
            ++cur;
            set.insert(intervals[i][1]);
            ret = max(ret, cur);
        }
        return ret;
    }
};