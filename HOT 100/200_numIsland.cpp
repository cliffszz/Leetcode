//https://leetcode-cn.com/problems/number-of-islands/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//DFS
class Solution {
public:
    int row, col;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < row && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < col && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int nums = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    nums++;
                    dfs(grid, i, j);
                }
            }
        }
        return nums;
    }
};

//BFS
class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int nums = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                queue<pair<int, int>> que;
                if (grid[i][j] == '1') {
                    nums++;
                    grid[i][j] = '0';
                    que.push({i, j});
                    while (!que.empty()) {
                        auto p = que.front();
                        que.pop();
                        int r = p.first, c = p.second;
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            que.push({r - 1, c});
                            grid[r - 1][c] = '0';
                        }
                        if (r + 1 < row && grid[r + 1][c] == '1') {
                            que.push({r + 1, c});
                            grid[r + 1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            que.push({r, c - 1});
                            grid[r][c - 1] = '0';
                        }
                        if (c + 1 < col && grid[r][c + 1] == '1') {
                            que.push({r, c + 1});
                            grid[r][c + 1] = '0';
                        }
                    }
                }
            }
        }
        return nums;
    }
};