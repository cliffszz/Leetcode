package mysort

// 自顶向下归并排序
func MergeSortDown(arr []int) {
	if len(arr) < 2 {
		return
	}
	mid := len(arr) / 2
	MergeSortDown(arr[:mid])
	MergeSortDown(arr[mid:])
	merge(arr[:mid], arr[mid:])
}

// 自底向上归并排序
func MergeSortUp(arr []int) {
	for size := 1; size <= len(arr); size += size {
		for i := 0; i < len(arr)-size; i += 2 * size {
			merge(arr[i:i+size], arr[i+size:min(i+2*size, len(arr))])
		}
	}
}

func merge(left, right []int) {
	res := []int{}
	i, j := 0, 0
	for {
		if i >= len(left) {
			res = append(res, right[j:]...)
			break
		}
		if j >= len(right) {
			res = append(res, left[i:]...)
			break
		}
		if left[i] < right[j] {
			res = append(res, left[i])
			i++
		} else {
			res = append(res, right[j])
			j++
		}
	}
	copy(left, res[:len(left)])
	copy(right, res[len(left):])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
