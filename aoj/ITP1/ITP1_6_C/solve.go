package main

import "fmt"

func main() {
	var n int
	var a [4][3][10]int
	fmt.Scanf("%d", &n)
	var b, f, r, v int
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d %d %d", &b, &f, &r, &v)
		a[b-1][f-1][r-1] += v
	}

	for i := 0; i < 4; i++ {
		for j := 0; j < 3; j++ {
			for k := 0; k < 10; k++ {
				fmt.Printf(" %d", a[i][j][k])
				if k == 9 {
					fmt.Println()
				}
			}
		}
		if i < 3 {
			fmt.Println("####################")
		}
	}
}
