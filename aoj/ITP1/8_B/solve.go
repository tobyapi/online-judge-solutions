package main

import "fmt"

func main() {
	var x string
	for {
		fmt.Scanf("%s", &x)
		if x == "0" {
			return
		}
		sum := 0
		for _, ch := range x {
			sum += int(ch - '0')
		}
		fmt.Println(sum)
	}
}
