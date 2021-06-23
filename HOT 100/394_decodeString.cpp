//https://leetcode-cn.com/problems/decode-string/
#include <string>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> stk;
        int n = 0;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                n *= 10;
                n += (s[i] - '0');
            } else {
                if (s[i] == '[') {
                    stk.push(make_pair(n, res));
                    n = 0;
                    res.clear();
                } else if (s[i] == ']') {
                    int k = stk.top().first;
                    string a = stk.top().second;
                    stk.pop();
                    for (int j = 0; j < k; j++) {
                        a += res;
                    }
                    res = a;
                } else {
                    res += s[i];
                }
            }
        }
        return res;
    }
};