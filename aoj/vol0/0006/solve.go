package main

import "fmt"

func rev(s string) string {
	r := []rune(s)
	size := len(s)
	for i := 0; i < len(s)/2; i++ {
		r[i], r[size-i-1] = r[size-i-1], r[i]
	}
	return string(r)
}

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(rev(s))
}
