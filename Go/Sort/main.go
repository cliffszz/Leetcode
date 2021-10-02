package main

import (
	"crypto/rand"
	"fmt"
	"main/mysort"
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
		mysort.BubbleSort(arr)
		fmt.Println("Bubble sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.SelectionSort(arr)
		fmt.Println("Selection sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.InsertSort(arr)
		fmt.Println("Insert sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.ShellSort(arr)
		fmt.Println("Shell sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.HeapSort(arr)
		fmt.Println("Heap sort time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.HeapSort2(arr)
		fmt.Println("Heap sort by container/heap time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.MergeSortDown(arr)
		fmt.Println("Merge sort top down time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.MergeSortUp(arr)
		fmt.Println("Merge sort bottom up time is:", time.Since(start))
		wg.Done()
	}()

	go func() {
		arr := randArr(10000)
		start := time.Now()
		mysort.QuickSort(arr)
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
