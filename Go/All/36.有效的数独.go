/*
 * @lc app=leetcode.cn id=36 lang=golang
 *
 * [36] 有效的数独
 */

// @lc code=start
func isValidSudoku(board [][]byte) bool {
    for i:=0;i<9;i++ {
        row := map[byte]bool{}
        col := map[byte]bool{}
        box := map[byte]bool{}
        for j:=0;j<9;j++ {
            if board[i][j] != '.' {
                if row[board[i][j]] {
                    return false
                }
                row[board[i][j]] = true
            }
            if board[j][i] != '.' {
                if col[board[j][i]] {
                    return false
                }
                col[board[j][i]] = true
            }
            r := (i%3)*3 + j%3
            c := (i/3)*3 + j/3
            if board[r][c] != '.' {
                if box[board[r][c]] {
                    return false
                }
                box[board[r][c]] = true
            }
            
        }
    }
    return true
}

// @lc code=end

