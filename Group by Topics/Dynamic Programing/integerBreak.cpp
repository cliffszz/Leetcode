//https://leetcode-cn.com/problems/integer-break/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<int>& arr) {
    int n = arr.size();
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i == n - 1) cout << "]";
        else cout << ", ";
    }
    cout << endl;
}

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        printArr(dp);
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
        
        int ret = Solution().integerBreak(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}