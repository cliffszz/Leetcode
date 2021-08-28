package offer2

func Divide(dividend int, divisor int) int {
	if dividend == -1<<31 && divisor == -1 {
		return 1<<31 - 1
	}

	isNegative := (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)
	var a = int64(dividend)
	var b = int64(divisor)
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	if a < b {
		return 0
	}

	shift := 31
	ret := 0
	// a 每次减去 b移shift位, 相当于 a - b * 2^shift
	for a >= b {
		for a < (b << shift) {
			shift--
		}
		a -= b << shift
		ret += 1 << shift
	}

	if isNegative {
		return -ret
	} else {
		return ret
	}
}
