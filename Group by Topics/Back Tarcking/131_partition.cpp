//https://leetcode-cn.com/problems/palindrome-partitioning/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backTracking(const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) { // 是回文子串
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {                // 如果不是则直接跳过
                continue;
            }
            backTracking(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back();        // 回溯过程，弹出本次已经填在的子串
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backTracking(s, 0);
        return result;
    }
};