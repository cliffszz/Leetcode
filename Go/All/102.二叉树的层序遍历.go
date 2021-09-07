/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
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
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res := make([][]int, 0)
	que := []*TreeNode{root}
	for len(que) > 0 {
		l := len(que)
		tmp := make([]int, 0)
		for i := 0; i < l; i++ {
			if que[i].Left != nil {
				que = append(que, que[i].Left)
			}
			if que[i].Right != nil {
				que = append(que, que[i].Right)
			}
			tmp = append(tmp, que[i].Val)
		}
		que = que[l:]
		res = append(res, tmp)
	}
	return res
}
// @lc code=end

