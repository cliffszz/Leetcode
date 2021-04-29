//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return s.size();
        unordered_set<char> set;
        set.insert(s[0]);
        int left = 0;
        int maxLen = 0;
        for (int right = 1; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left++]);
            }
            maxLen = max(maxLen, right - left + 1);
            set.insert(s[right]);
        }
        return maxLen;
    }
};