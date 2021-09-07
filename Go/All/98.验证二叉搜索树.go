/*
 * @lc app=leetcode.cn id=98 lang=golang
 *
 * [98] 验证二叉搜索树
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
func isValidBST(root *TreeNode) bool {
	max := 1<<32-1
	min := -(1<<32)
	return isValid(root, min, max)
}

func isValid(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}
	v := root.Val
	return v > min && v < max && isValid(root.Left, min, v) && isValid(root.Right, v, max)
}
// @lc code=end

