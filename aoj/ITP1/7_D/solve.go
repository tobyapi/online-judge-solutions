package main

import "fmt"

func main() {
	var n, m, l int
	fmt.Scanf("%d %d %d", &n, &m, &l)

	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Scanf("%d", &a[i][j])
		}
	}

	b := make([][]int, m)
	for i := 0; i < m; i++ {
		b[i] = make([]int, l)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < l; j++ {
			fmt.Scanf("%d", &b[i][j])
		}
	}

	result := make([][]int, n)
	for i := 0; i < n; i++ {
		result[i] = make([]int, l)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			for k := 0; k < l; k++ {
				result[i][k] += a[i][j] * b[j][k]
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < l; j++ {
			fmt.Printf("%d", result[i][j])
			if j < l-1 {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
}
