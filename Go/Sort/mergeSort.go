package main

// 自顶向下归并排序
func mergeSortDown(arr []int) {
	res := mergeSort(arr)
	copy(arr, res)
}

func mergeSort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}
	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])
	return mergeDown(left, right)
}

func mergeDown(left, right []int) []int {
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
	return res
}

// 自底向上归并排序
func mergeSortUp(arr []int) {
	if len(arr) < 2 {
		return
	}
	mid := len(arr) / 2
	mergeSortUp(arr[:mid])
	mergeSortUp(arr[mid:])
	mergeUp(arr)
}

func mergeUp(arr []int) {
	mid := len(arr) / 2
	i, j := 0, mid
	for i <= mid && j < len(arr) {
		if arr[i] <= arr[j] {
			i++
		} else {
			// 右边区域的数字比左边区域小，于是他站了起来
			v, t := arr[j], j
			// 前面的数字不断后移
			for t > i {
				arr[t] = arr[t-1]
				t--
			}
			// 这个数字做到i所在的位置上
			arr[t] = v
			// 更新所有下标，使其前进一格
			i++
			j++
			mid++
		}
	}
}
