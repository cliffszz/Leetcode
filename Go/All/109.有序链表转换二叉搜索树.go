/*
 * @lc app=leetcode.cn id=109 lang=golang
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//Definition for a binary tree node.
/*
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
*/

func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	if head != nil && head.Next == nil {
		return &TreeNode{Val: head.Val, Left: nil, Right: nil}
	}
	mid, pre := middleNodeAndPreNode(head)
	if mid == nil {
		return nil
	}
	if pre != nil {
		pre.Next = nil
	}
	if mid == head {
		head = nil
	}
	return &TreeNode{Val: mid.Val, Left: sortedListToBST(head), Right: sortedListToBST(mid.Next)}
}

func middleNodeAndPreNode(head *ListNode) (middle *ListNode, pre *ListNode) {
	if head == nil || head.Next == nil {
		return nil, head
	}
	p1 := head
	p2 := head
	for p2.Next != nil && p2.Next.Next != nil {
		pre = p1
		p1 = p1.Next
		p2 = p2.Next.Next
	}
	return p1, pre
}

// @lc code=end

