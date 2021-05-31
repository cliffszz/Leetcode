//https://leetcode-cn.com/problems/climbing-stairs/
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1] = {0};
        //dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << "[";
        for(int i = 0; i < n + 1; i++) {
            cout << dp[i];
            if(i == n) cout << "]" << endl;
            else cout << ", ";
        }
        return dp[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}