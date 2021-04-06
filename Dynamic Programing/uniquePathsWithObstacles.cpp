//https://leetcode-cn.com/problems/unique-paths-ii/
#include <iostream>
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        printMat(dp);
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}