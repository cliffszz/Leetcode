package offer

func MinArray(numbers []int) int {
	for i := 1; i < len(numbers); i++ {
		if numbers[i] < numbers[i-1] {
			return numbers[i]
		}
	}
	return numbers[0]
}

func MinArray2(numbers []int) int {
	l, r := 0, len(numbers)-1
	for l < r {
		m := l + (r-l)/2
		if numbers[m] > numbers[r] {
			l = m + 1
		} else if numbers[m] < numbers[r] {
			r = m
		} else {
			r--
		}
	}
	return numbers[l]
}
