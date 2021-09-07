/*
 * @lc app=leetcode.cn id=95 lang=golang
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{}
	}
	return generateBSTrees(1, n)
}

func generateBSTrees(start, end int) (tree []*TreeNode) {
	if start > end {
		tree = append(tree, nil)
		return
	}
	for i := start; i <= end; i++ {
		left := generateBSTrees(start, i-1)
		right := generateBSTrees(i+1, end)
		for _, l := range left {
			for _, r := range right {
				root := &TreeNode{Val: i, Left: l, Right: r}
				tree = append(tree, root)
			}
		}
	}
	return 
}
// @lc code=end

