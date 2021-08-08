package offer

func NumWays(n int) int {
	a, b := 1, 1
	for i := 2; i <= n+1; i++ {
		a, b = b, (a+b)%1000000007
	}
	return a
}
