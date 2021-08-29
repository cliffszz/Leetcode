package offer2

import (
	"strconv"
)

func AddBinary(a string, b string) string {
	res := ""
	i, j := len(a)-1, len(b)-1
	carry := 0
	for i >= 0 || j >= 0 {
		var bitA, bitB int
		if i < 0 {
			bitA = 0
		} else {
			bitA = int(a[i] - '0')
		}

		if j < 0 {
			bitB = 0
		} else {
			bitB = int(b[j] - '0')
		}

		sum := bitA + bitB + carry
        carry = sum / 2
		res = strconv.Itoa(sum%2) + res
        i--
        j--
	}
	if carry == 1 {
		res = "1" + res
	}
	return res
}
