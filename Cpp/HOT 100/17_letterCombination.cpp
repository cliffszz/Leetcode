//https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    const vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string s;
    void backTracking(const string digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = key[digit];
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backTracking(digits, index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        s.clear();
        if (digits.size() == 0) return res;
        backTracking(digits, 0);
        return res;
    }
};