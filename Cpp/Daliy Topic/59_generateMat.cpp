//https://leetcode-cn.com/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        int up = 0, down = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while(1){
            for(int i = left; i <= right; i++) mat[up][i] = num++;
            if(++up > down) break;
            for(int i = up; i <= down; i++) mat[i][right] = num++;
            if(--right < left) break;
            for(int i = right; i >= left; i--) mat[down][i] = num++;
            if(--down < up) break;
            for(int i = down; i >= up; i--) mat[i][left] = num++;
            if(++left > right) break;
        }

        return mat;
    }
};

int main(){

    Solution solution;

    vector<vector<int>> mat = solution.generateMatrix(3);
    int n = mat.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
            if(i == n - 1 && j == n - 1) cout << endl;
            else cout << ",";
        }
    }

    return 0;
}


