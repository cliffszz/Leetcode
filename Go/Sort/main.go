package main

import "fmt"

func main() {
	arr := []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	bubbleSort(arr)
	fmt.Println(arr)

	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	selectionSort(arr)
	fmt.Println(arr)

	arr = []int{2, 1, 5, 6, 7, 4, 8, 9, 3}
	fmt.Println(arr)
	insertSort(arr)
	fmt.Println(arr)
}
