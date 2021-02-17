package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	var in = make([]int, 3)

	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d %d", &in[0], &in[1], &in[2])
		sort.Ints(in)

		var a = in[0]
		var b = in[1]
		var c = in[2]

		if a*a+b*b == c*c {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
