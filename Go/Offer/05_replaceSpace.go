package offer

func replaceSpace(s string) string {
	b := []byte(s)
	res := make([]byte, 0)
	for _, c := range b {
		if c == ' ' {
			res = append(res, []byte("%20")...)
		} else {
			res = append(res, c)
		}
	}
	return string(res)
}

func replaceSpace2(s string) string {
	b := []byte(s)
	l := len(s)
	cnt := 0
	for _, c := range s {
		if c == ' ' {
			cnt++
		}
	}
	recnt := cnt * 2
	tmp := make([]byte, recnt)
	b = append(b, tmp...)
	i := l - 1
	j := len(b) - 1
	for i >= 0 {
		if b[i] == ' ' {
			b[j-2], b[j-1], b[j] = '%', '2', '0'
			i--
			j -= 3
		} else {
			b[j] = b[i]
			i--
			j--
		}
	}
	return string(b)
}
