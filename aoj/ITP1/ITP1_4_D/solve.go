package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var min int64 = 1 << 29
	max := -min
	var sum int64 = 0
	for i := 0; i < n; i++ {
		if a[i] < min {
			min = a[i]
		}
		if max < a[i] {
			max = a[i]
		}
		sum += a[i]
	}
	fmt.Printf("%d %d %d\n", min, max, sum)
}
