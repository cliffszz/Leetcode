package offer

func Fib(n int) int {
	dp := make([]int, n+2)
	dp[0], dp[1] = 0, 1
	for i := 2; i <= n; i++ {
		dp[i] = (dp[i-1] + dp[i-2]) % 1000000007
	}
	return dp[n]
}

func Fib2(n int) int {
	a, b := 0, 1
	for i := 2; i <= n+1; i++ {
		a, b = b, (a+b)%1000000007
	}
	return a
}
