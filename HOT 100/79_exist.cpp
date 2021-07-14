//https://leetcode-cn.com/problems/word-search/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int k, int i, int j) {
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '0';
        if(dfs(board, word, k + 1, i + 1, j) || dfs(board, word, k + 1, i, j + 1)
        || dfs(board, word, k + 1, i - 1, j) || dfs(board, word, k + 1, i, j - 1)) {
            return true;
        }
        board[i][j] = word[k];
        return false;
    }
};