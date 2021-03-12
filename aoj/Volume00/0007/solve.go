package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	sum := 100000
	for i := 0; i < n; i++ {
		sum += (sum / 20)
		if sum%1000 != 0 {
			sum -= sum % 1000
			sum += 1000
		}
	}
	fmt.Println(sum)
}
