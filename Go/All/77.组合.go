/*
 * @lc app=leetcode.cn id=77 lang=golang
 *
 * [77] 组合
 */

// @lc code=start
func combine(n int, k int) [][]int {
	if n <= 0 || k <= 0 || k > n {
		return [][]int{}
	}
	c, res := []int{}, [][]int{}
	findCombine(n, k, 1, c, &res)
	return res
}

func findCombine(n, k, index int, c []int, res *[][]int) {
	for len(c) == k {
		t := make([]int, len(c))
		copy(t, c)
		*res = append(*res, t)
		return 
	}
	for i := index; i <= n-(k-len(c))+1; i++ {
		c = append(c, i)
		findCombine(n, k, i+1, c, res)
		c = c[:len(c)-1]
	}
}
// @lc code=end

