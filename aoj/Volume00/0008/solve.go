package main

import "fmt"

func main() {
	var n int

	for {
		i, _ := fmt.Scan(&n)
		if i != 1 {
			return
		}
		sum := 0
		for a := 0; a < 10; a++ {
			for b := 0; b < 10; b++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						if a+b+c+d == n {
							sum++
						}
					}
				}
			}
		}
		fmt.Println(sum)
	}
}
