//https://leetcode-cn.com/problems/minimum-window-substring/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        for (char c : t) need[c]++;
        while (right < s.size()) {
            //进入滑动窗口的字符
            char c = s[right];
            right++;
            //在t中，计数+1，相等说明该字母数量已满足
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            //全部满足后，滑动窗口缩小
            while (valid == need.size()) {
                //记录新的最小值和起始位置
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                //移出滑动窗口的字符
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};