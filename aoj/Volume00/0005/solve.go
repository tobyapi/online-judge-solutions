package main

import (
	"fmt"
)

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, int(a%b)
	}
	return a
}

func lcm(a int, b int) int {
	return a / gcd(a, b) * b
}

func main() {
	var a, b int

	for {
		n, _ := fmt.Scan(&a, &b)
		if n != 2 {
			return
		}
		fmt.Printf("%d %d\n", gcd(a, b), lcm(a, b))
	}
}
