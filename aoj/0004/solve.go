package main

import "fmt"

func main() {
	var a, b, c, d, e, f float32

	for {
		n, _ := fmt.Scan(&a, &b, &c, &d, &e, &f)
		if n != 6 {
			return
		}

		y := (f - d*c/a) / (e - b*d/a)
		x := (c - b*y) / a

		fmt.Printf("%.3f %.3f\n", x, y)
	}
}
