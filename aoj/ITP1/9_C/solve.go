package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	res_a := 0
	res_b := 0
	for i := 0; i < n; i++ {
		var a, b string
		fmt.Scan(&a)
		fmt.Scan(&b)
		if a > b {
			res_a += 3
		} else if a < b {
			res_b += 3
		} else {
			res_a++
			res_b++
		}
	}
	fmt.Printf("%d %d\n", res_a, res_b)
}
