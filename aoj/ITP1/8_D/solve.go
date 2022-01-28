package main

import "fmt"

func solve(s string, p string) bool {
	for i := 0; i < len(s); i++ {
		cnt := 0
		for j := 0; j < len(p); j++ {
			if s[(i+j)%len(s)] == p[cnt] {
				cnt++
			}
		}
		if cnt == len(p) {
			return true
		}
	}
	return false
}

func main() {
	var s, p string
	fmt.Scanf("%s", &s)
	fmt.Scanf("%s", &p)
	if solve(s, p) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
