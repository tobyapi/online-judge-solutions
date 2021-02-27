package main

import "fmt"

func main() {
	var w int
	var n int

	fmt.Scan(&w, &n)
	var d = make([]int, w+1)

	for i := 0; i <= w; i++ {
		d[i] = i
	}

	var a int
	var b int
	for i := 0; i < n; i++ {
		fmt.Scanf("%d,%d", &a, &b)
		d[a], d[b] = d[b], d[a]
	}

	for i := 1; i <= w; i++ {
		fmt.Println(d[i])
	}
}
