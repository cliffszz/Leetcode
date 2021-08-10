package offer

func MyPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	res := float64(1)
	if n < 0 {
		x, n = 1/x, -n
	}
	for n > 0 {
		if n&1 > 0 {
			res *= x
		}
		x *= x
		n >>= 1
	}
	return res
}
