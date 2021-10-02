package main

import (
	"crypto/rand"
	"fmt"
	"math/big"
	"sync"
	"time"
)

func main() {
	wg := sync.WaitGroup{}
	wg.Add(9)

	go func() {
		arr := randArr(10000)
		start := time.Now()
		bubbleSort(arr)
		fmt.Println("Bubble sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		selectionSort(arr)
		fmt.Println("Selection sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		insertSort(arr)
		fmt.Println("Insert sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		shellSort(arr)
		fmt.Println("Shell sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		heapSort(arr)
		fmt.Println("Heap sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		heapSort2(arr)
		fmt.Println("Heap sort by container/heap time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mergeSortDown(arr)
		fmt.Println("Merge sort top down time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mergeSortUp(arr)
		fmt.Println("Merge sort bottom up time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		quickSort(arr)
		fmt.Println("Quick sort time is:", time.Since(start))
		wg.Done()
	}()

	wg.Wait()
}

func randArr(n int) []int {
	arr := []int{}
	for i := 0; i < n; i++ {
		n, _ := rand.Int(rand.Reader, big.NewInt(int64(n)))
		arr = append(arr, int(n.Int64()))
	}
	return arr
}
