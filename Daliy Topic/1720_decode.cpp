//https://leetcode-cn.com/problems/decode-xored-array/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1);
        res[0] = first;
        for (int i = 1; i < encoded.size() + 1; i++) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
};