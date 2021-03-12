package main

import "fmt"

func f(x float64) float64 {
	return x * x
}

func main() {
	for {
		var d float64
		n, _ := fmt.Scan(&d)
		if n != 1 {
			return
		}

		res := 0.0
		for i := 1.0; i*d < 600; i++ {
			res += f(i*d) * d
		}
		fmt.Printf("%.0f\n", res)
	}
}
