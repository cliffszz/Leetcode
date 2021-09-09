/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 */

// @lc code=start
func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	p, res, used := []int{}, [][]int{}, make([]bool, len(nums))
	dfs(nums, p, 0, &res, &used)
	return res
}

func dfs(nums, p []int, index int, res *[][]int, used *[]bool) {
	if index == len(nums) {
		tmp := make([]int, len(p))
		copy(tmp, p)
		*res = append(*res, tmp)
	}
	for i := 0; i < len(nums); i++ {
		if !(*used)[i] {
			(*used)[i] = true
			p = append(p, nums[i])
			dfs(nums, p, index+1, res, used)
			p = p[:len(p)-1]
			(*used)[i] = false
		}
	}
}
// @lc code=end

