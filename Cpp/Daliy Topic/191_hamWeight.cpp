//https://leetcode-cn.com/problems/number-of-1-bits/
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
       int cnt = 0;
       /*
       for(int i = 0; i < 32; i++) {
           if(n & (1 << i)) cnt++;
       }
       */
      while(n) {
          n &= n - 1;
          cnt++;
      }
      return cnt; 
    }
};

int main() {
    Solution solution;
    uint32_t n = 11111111111111111111111111111101;
    cout << solution.hammingWeight(n) << endl;
    return 0;
}