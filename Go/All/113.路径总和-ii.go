/*
 * @lc app=leetcode.cn id=113 lang=golang
 *
 * [113] 路径总和 II
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
func pathSum(root *TreeNode, sum int) [][]int {
	slice := [][]int{}
	slice = findPath(root, sum, slice, []int(nil))
	return slice
}

func findPath(n *TreeNode, sum int, slice [][]int, stack []int) [][]int {
	if n == nil {
		return slice
	}
	sum -= n.Val
	stack = append(stack, n.Val)
	if sum == 0 && n.Left == nil && n.Right == nil {
		slice = append(slice, append([]int{}, stack...))
		stack = stack[:len(stack)-1]
	}
	slice = findPath(n.Left, sum, slice, stack)
	slice = findPath(n.Right, sum, slice, stack)
	return slice
}
// @lc code=end

