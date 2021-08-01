//https://leetcode-cn.com/problems/excel-sheet-column-title/
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber) {
            int a = (columnNumber - 1) % 26 + 1;
            res += a - 1 + 'A';
            columnNumber = (columnNumber - a) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};