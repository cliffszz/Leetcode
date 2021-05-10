//https://leetcode-cn.com/problems/generate-parentheses/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> res;
    string path;
    void backTracking(int open, int close, int n) {
        if (open + close == n * 2) {
            res.push_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            backTracking(open + 1, close, n);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            backTracking(open, close + 1, n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        path.clear();
        backTracking(0, 0, n);
        return res;
    }
};