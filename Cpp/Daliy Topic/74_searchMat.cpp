//https://leetcode-cn.com/problems/search-a-2d-matrix/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0 || col == 0) return false;
        int r = 0; int c = col - 1;
        while(r < row && c >=0) {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) r++;
            else c--;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    //vector<vector<int>> matrix = {{1},{3}};
    int target = 13;
    bool ret = Solution().searchMatrix(matrix, target);
    if(ret) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}