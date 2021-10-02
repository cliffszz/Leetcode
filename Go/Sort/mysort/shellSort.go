package mysort

func ShellSort(arr []int) {
	// 增量序列
	for gap := len(arr) / 2; gap > 0; gap /= 2 {
		// 分组
		l := len(arr) / gap
		for index := 0; index < gap; index += l {
			// 插入排序
			InsertSort(arr[index : index+l])
		}
	}
}
