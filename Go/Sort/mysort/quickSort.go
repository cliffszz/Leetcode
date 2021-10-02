package mysort

func QuickSort(arr []int) {
	// 区间内少于两个数，退出递归
	if len(arr) < 2 {
		return
	}
	// 找到中间值
	mid := partition(arr)
	// 递归对左半部分快排
	QuickSort(arr[:mid])
	// 递归对右半部分快排
	QuickSort(arr[mid+1:])
}

func partition(arr []int) int {
	pivot := arr[0]
	left, right := 1, len(arr)-1
	for left < right {
		// 找到第一个大于基数的位置
		for left < right && arr[left] <= pivot {
			left++
		}
		// 交换这两个数，是的区间内左半部分小于或等于基数，右半部分都大于或等于基数
		if left != right {
			arr[left], arr[right] = arr[right], arr[left]
			right--
		}
	}
	// 如果left和right相等，单独比较right和pivot
	if left == right && arr[right] > pivot {
		right--
	}
	// 将基数和中间数交换
	if right != 0 {
		arr[0], arr[right] = arr[right], arr[0]
	}
	// 返回中间值的下标
	return right
}
