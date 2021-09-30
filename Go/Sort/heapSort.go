package main

import (
	"container/heap"
	"fmt"
)

func heapSort(arr []int) {
	bulidMaxHeap(arr)
	for i := len(arr) - 1; i >= 0; i-- {
		// 将最大值放在数组最后
		arr[0], arr[i] = arr[i], arr[0]
		// 调整剩余数组，使其满足大顶堆
		maxHeapify(arr, 0, i)
	}
}

// 初始构建大顶堆
func bulidMaxHeap(arr []int) {
	// 从最后一个非叶子节点开始构建大顶堆
	for i := len(arr)/2 - 1; i >= 0; i-- {
		maxHeapify(arr, i, len(arr))
	}
}

// 调整大顶堆，最后一个参数为剩余未排序的数字数量，即堆的大小
func maxHeapify(arr []int, index, heapSize int) {
	left, right := index+1, index+2
	largest := index
	if left < heapSize && arr[left] > arr[largest] {
		largest = left
	}
	if right < heapSize && arr[right] > arr[largest] {
		largest = right
	}
	if largest != index {
		// 将最大值交换为根节点
		arr[index], arr[largest] = arr[largest], arr[index]
		// 调整交换后的大顶堆
		maxHeapify(arr, largest, heapSize)
	}
}

// 利用标准库实现堆排序
func heapSort2(arr []int) {
	mh := maxHeap{}
	for _, a := range arr {
		heap.Push(&mh, a)
	}
	fmt.Println(mh)
	for i := 0; i < mh.Len(); i++ {
		arr[i] = heap.Pop(&mh).(int)
	}
}

type maxHeap []int

func (mh maxHeap) Len() int {
	return len(mh)
}

func (mh maxHeap) Less(i, j int) bool {
	// 小于表示大顶堆，大于表示小顶堆
	return mh[i] < mh[j]
}

func (mh maxHeap) Swap(i, j int) {
	mh[i], mh[j] = mh[j], mh[i]
}

func (mh *maxHeap) Push(x interface{}) {
	*mh = append(*mh, x.(int))
}

func (mh *maxHeap) Pop() interface{} {
	x := (*mh)[len(*mh)-1]
	(*mh) = (*mh)[:len(*mh)-1]
	return x
}
