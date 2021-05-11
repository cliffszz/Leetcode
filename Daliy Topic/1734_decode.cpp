//https://leetcode-cn.com/problems/decode-xored-permutation/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> perm(encoded.size() + 1);
        int total = 0;
        for (int i = 1; i <= encoded.size() + 1; i++) {
            total ^= i;
        }
        int odd = 0;
        for (int i = 1; i < encoded.size(); i += 2) {
            odd ^= encoded[i];
        }
        perm[0] = total ^ odd;
        for (int i = 0; i < encoded.size(); i++) {
            perm[i + 1] = perm[i] ^ encoded[i];
        }
        return perm;
    }
};