//https://leetcode-cn.com/problems/n-queens/
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
public:
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        //检查列是否冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }
        //检查右对角线是否冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        //检查左对角线是否冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void backTrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) continue;
            board[row][col] = 'Q';
            backTrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //'.'表示空，'Q'表示皇后，初始化空棋盘
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0);
        return res;
    }
};