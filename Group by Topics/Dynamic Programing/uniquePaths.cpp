////https://leetcode-cn.com/problems/unique-paths/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void printMat(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0; i < m; i++) {
            vector<int> row;
            for(int j = 0; j < n; j++) {
                row.push_back(mat[i][j]);
            }
            cout << "[";
            for(int j = 0; j < n; j++) {
                cout << row[j];
                if(j == n - 1) cout << "]";
                else cout << ", ";
            }
            cout << endl;
        }
        cout << endl;
}

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        printMat(dp);
        return dp[m-1][n-1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}