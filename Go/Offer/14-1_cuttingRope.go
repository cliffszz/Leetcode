package offer

func CuttingRope(n int) int {
	dp := make([]int, n+1)
	dp[2] = 1
	for i := 3; i <= n; i++ {
		for j := 2; j < i; j++ {
			dp[i] = MaxOfInt(dp[i], MaxOfInt(j*(i-j), j*dp[i-j]))
		}
	}
	return dp[n]
}

func MaxOfInt(i int, j int) int {
	if i < j {
		return j
	} else {
		return i
	}
}
