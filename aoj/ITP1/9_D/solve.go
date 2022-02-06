package main

import (
	"fmt"
)

func reverse(s string, a int, b int) string {
	rs := []rune(s[a : b+1])
	for i := 0; i*2 < len(rs); i++ {
		rs[i], rs[len(rs)-i-1] = rs[len(rs)-i-1], rs[i]
	}
	return s[:a] + string(rs) + s[b+1:]
}

func replace(s string, a int, b int, p string) string {
	return s[:a] + p + s[b+1:]
}

func main() {
	var s string
	var q int
	var command string
	var a, b int
	var p string

	fmt.Scan(&s)
	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		fmt.Scan(&command)
		fmt.Scan(&a)
		fmt.Scan(&b)
		if command == "replace" {
			fmt.Scan(&p)
			s = replace(s, a, b, p)
		} else if command == "reverse" {
			s = reverse(s, a, b)
		} else if command == "print" {
			fmt.Println(s[a : b+1])
		}
	}
}
