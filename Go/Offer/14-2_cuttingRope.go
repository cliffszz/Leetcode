package offer

func CuttingRope2(n int) int {
	if n <= 3 {
		return n - 1
	}

	b := n % 3
	rem := int64(1)
	x := int64(3)
	p := int64(1000000007)
	for a := n/3 - 1; a > 0; a >>= 1 {
		if (a & 1) == 1 {
			rem = (x * rem) % p
		}
		x = (x * x) % p
	}

	if b == 0 {
		return (int)(rem * 3 % p)
	} else if b == 1 {
		return (int)(rem * 4 % p)
	}

	return (int)(rem * 6 % p)
}
