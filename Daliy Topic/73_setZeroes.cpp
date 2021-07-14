//https://leetcode-cn.com/problems/set-matrix-zeroes/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m), col(n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {

    vector<vector<int>> matrix = {  {0,1,2,0},
                                    {3,4,5,2},
                                    {1,3,1,5} };
    int m = matrix.size();
    int n = matrix[0].size();
    Solution solution;
    solution.setZeroes(matrix);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
