package offer

type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	res := make([]int, 0)
	backTracking(head, &res)
	return res
}

func backTracking(head *ListNode, res *[]int) {
	if head == nil {
		return
	}
	backTracking(head.Next, res)
	*res = append(*res, head.Val)
}

func reversePrint2(head *ListNode) []int {
	if head == nil {
		return nil
	}
	res := []int{}
	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}
	for i, j := 0, len(res)-1; i < j; {
		res[i], res[j] = res[j], res[i]
		i++
		j--
	}
	return res
}
