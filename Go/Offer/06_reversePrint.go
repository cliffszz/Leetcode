package offer

type ListNode struct {
	Val  int
	Next *ListNode
}

func ReversePrint(head *ListNode) []int {
	res := make([]int, 0)
	BackTracking(head, &res)
	return res
}

func BackTracking(head *ListNode, res *[]int) {
	if head == nil {
		return
	}
	BackTracking(head.Next, res)
	*res = append(*res, head.Val)
}

func BeversePrint2(head *ListNode) []int {
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
