package main

import (
	"fmt"
	"math"
)

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, int(a%b)
	}
	return int(math.Abs(float64(a)))
}

func lcm(a int, b int) int {
	return int(math.Abs(float64(a / gcd(a, b) * b)))
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
