package main

import (
	"fmt"
	"sort"
)

func main() {
	var m = make([]int, 10)

	for i := 0; i < 10; i++ {
		fmt.Scanf("%d", &m[i])
	}

	sort.Ints(m)
	fmt.Printf("%d\n%d\n%d\n", m[9], m[8], m[7])
}
