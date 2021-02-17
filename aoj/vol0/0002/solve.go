package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int
	var b int

	for {
		_, err := fmt.Scanf("%d %d", &a, &b)
		if err != nil {
			return
		}
		fmt.Println(len(strconv.Itoa(a + b)))
	}
}
