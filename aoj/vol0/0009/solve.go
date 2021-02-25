package main

import "fmt"

func fill(n int) []bool {
	s := make([]bool, n)
	for i := range s {
		s[i] = true
	}
	return s
}

func primes(n int) []bool {
	list := fill(n)
	list[0] = false
	list[1] = false
	for i := 2; i*i < n; i++ {
		if !list[i] {
			continue
		}
		for j := i * i; j < n; j += i {
			list[j] = false
		}
	}
	return list
}

func main() {
	isPrime := primes(1000000)
	sum := [1000000]int{}
	for i := 2; i < 1000000; i++ {
		sum[i] += sum[i-1]
		if isPrime[i] {
			sum[i]++
		}
	}

	var n int

	for {
		a, _ := fmt.Scan(&n)
		if a != 1 {
			return
		}
		fmt.Println(sum[n])
	}
}
