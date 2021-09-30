package main

func insertSort(arr []int) {
	// 从第二个数开始往前插入数字
	for i := 1; i < len(arr); i++ {
		j := i
		for j >= 1 && arr[j] < arr[j-1] {
			arr[j-1], arr[j] = arr[j], arr[j-1]
			j--
		}
	}
}
