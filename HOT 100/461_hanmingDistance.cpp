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

//我们可以使用Brian Kernighan算法进行优化，
//具体地，该算法可以被描述为这样一个结论：记 f(x) 表示 x 和 x-1 进行与运算所得的结果
//(即 f(x)=x&(x-1))，那么 f(x) 恰为 x 删去其二进制表示中最右侧的 1 的结果。

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