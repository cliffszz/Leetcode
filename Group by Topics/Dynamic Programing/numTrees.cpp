//https://leetcode-cn.com/problems/unique-binary-search-trees/
#include <iostream>
#include <vector>

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
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
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
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}