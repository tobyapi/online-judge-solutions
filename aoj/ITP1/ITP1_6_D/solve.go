package main

import "fmt"

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)

	b := make([]int, m)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Scanf("%d", &a[i][j])
		}
	}

	for i := 0; i < m; i++ {
		fmt.Scanf("%d", &b[i])
	}

	for i := 0; i < n; i++ {
		sum := 0
		for j := 0; j < m; j++ {
			sum += a[i][j] * b[j]
		}
		fmt.Println(sum)
	}
}
