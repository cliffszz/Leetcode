package offer

func HammingWeight(num uint32) (cnt int) {
	for ; num > 0; num &= num - 1 {
		cnt++
	}
	return
}

func HammingWeight2(num uint32) int {
	cnt := 0
	for ; num > 0; num &= num - 1 {
		cnt++
	}
	return cnt
}
