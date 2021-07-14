//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <string>
#include <unordered_map>
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

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int maxLen = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};