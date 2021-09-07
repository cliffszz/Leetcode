/*
 * @lc app=leetcode.cn id=105 lang=golang
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{Val: preorder[0]}
	for pos, node := range inorder {
		if node == root.Val {
			root.Left = buildTree(preorder[1:pos+1], inorder[:pos])
			root.Right = buildTree(preorder[pos+1:], inorder[pos+1:])
		}
	}
	return root
}
// @lc code=end

