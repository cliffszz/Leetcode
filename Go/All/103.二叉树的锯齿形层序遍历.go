/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
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
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res := [][]int{}
	que := []*TreeNode{root}
	flag := true
	for len(que) > 0 {
		l := len(que)
		tmp := make([]int, l)
		j := l-1
		for i := 0; i < l; i++ {
			if flag {
				tmp[i] = que[i].Val
			} else {
				tmp[j] = que[i].Val
				j--
			}
			if que[i].Left != nil {
				que = append(que, que[i].Left)
			}
			if que[i].Right != nil {
				que = append(que, que[i].Right)
			}
		}
		que = que[l:]
		res = append(res, tmp)
		flag = !flag
	}
	return res
}
// @lc code=end

