//https://leetcode-cn.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int s = x ^ y;
        while (s) {
            res += s & 1;
            s >>= 1;
        }
        return res;
    }
};

class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            s &= s - 1;
            ret++;
        }
        return ret;
    }
};