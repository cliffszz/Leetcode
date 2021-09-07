/*
 * @lc app=leetcode.cn id=106 lang=golang
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}
	l := len(postorder)
	root := &TreeNode{Val: postorder[l-1]}
	postorder = postorder[:l-1]
	for pos, val := range inorder {
		if val == root.Val {
			root.Left = buildTree(inorder[:pos], postorder[:len(inorder[:pos])])
			root.Right = buildTree(inorder[pos+1:], postorder[len(inorder[:pos]):])
		}
	}
	return root
}
// @lc code=end

