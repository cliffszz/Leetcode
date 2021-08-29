package offer2

func CountBits(n int) []int {
	res := make([]int, n+1)
	res[0] = 0

	for i := 1; i <= n; i++ {
		res[i] = res[i&(i-1)] + 1
	}

	return res
}
