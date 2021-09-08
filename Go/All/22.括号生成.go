/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 */

// @lc code=start
func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{}
	}
	res := make([]string, 0)
	genPar(n, n, "", &res)
	return res
}

func genPar(l, r int, s string, res *[]string) {
	if l == 0 && r == 0 {
		*res = append(*res, s)
		return
	}
	if l > 0 {
		genPar(l-1, r, s+"(", res)
	}
	if r > l && r > 0 {
		genPar(l, r-1, s+")", res)
	}
}
// @lc code=end

