package main

import "fmt"

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	fmt.Printf("%d %d %0.5f\n", a/b, a%b, float64(a)/float64(b))
}
