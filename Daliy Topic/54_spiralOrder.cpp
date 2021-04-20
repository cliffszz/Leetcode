//https://leetcode-cn.com/problems/spiral-matrix/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(!matrix.size()) return res;

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int button = matrix.size() - 1;

        while(1){
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);//right
            if(++top > button) break;
            for(int i = top; i <= button; i++) res.push_back(matrix[i][right]);//down 
            if(--right < left) break;
            for(int i = right; i >= left; i--) res.push_back(matrix[button][i]);//left
            if(--button < top) break;
            for(int i = button; i >= top; i--) res.push_back(matrix[i][left]);//up
            if(++left > right) break;
        }

        return res;
    }
};

int main(){

    Solution solution;

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8},{9, 10, 11, 12}};

    vector<int> res = solution.spiralOrder(mat);

    for(int i = 0; i < res.size(); i++){
        if(i == 0) cout << "[";
        cout << res[i];
        if(i == res.size() - 1) cout << "]" << endl;
        else cout << ",";
    }
    
    return 0;
}


