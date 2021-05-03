//https://leetcode-cn.com/problems/reverse-integer/
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res < INT_MIN / 10 || res > INT_MAX / 10) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};