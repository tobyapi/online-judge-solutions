package main

import "fmt"

func main() {
	var r, c int
	fmt.Scanf("%d %d", &r, &c)

	sum_c := make([]int, c+1)

	for i := 0; i < r; i++ {
		sum := 0
		for j := 0; j < c; j++ {
			var e int
			fmt.Scanf("%d", &e)
			fmt.Printf("%d ", e)
			sum += e
			sum_c[j] += e
		}
		fmt.Printf("%d\n", sum)
		sum_c[c] += sum
	}

	for i := 0; i < c; i++ {
		fmt.Printf("%d ", sum_c[i])
	}
	fmt.Printf("%d\n", sum_c[c])
}
