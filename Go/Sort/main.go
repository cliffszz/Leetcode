package main

import (
	"fmt"
)

func main() {
	fmt.Println("Bubble sort")
	arr := []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	bubbleSort(arr)
	fmt.Println(arr)

	fmt.Println("Selection sort")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	selectionSort(arr)
	fmt.Println(arr)

	fmt.Println("Insert sort")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	insertSort(arr)
	fmt.Println(arr)

	fmt.Println("Shell sort")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	shellSort(arr)
	fmt.Println(arr)

	fmt.Println("Heap sort")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	heapSort(arr)
	fmt.Println(arr)

	fmt.Println("Heap sort by container/heap")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	heapSort2(arr)
	fmt.Println(arr)

	fmt.Println("Quick sort")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	quickSort(arr)
	fmt.Println(arr)

	fmt.Println("Merge sort top down")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	mergeSortDown(arr)
	fmt.Println(arr)

	fmt.Println("Merge sort bottom up")
	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	mergeSortUp(arr)
	fmt.Println(arr)
}
