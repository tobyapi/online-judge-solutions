package main

import "fmt"

func main() {
	var m, f, r int
	for {
		fmt.Scanf("%d %d %d", &m, &f, &r)
		if m < 0 && f < 0 && r < 0 {
			break
		}

		if m < 0 || f < 0 {
			fmt.Println("F")
		} else if 80 <= m+f {
			fmt.Println("A")
		} else if 65 <= m+f && m+f < 80 {
			fmt.Println("B")
		} else if 50 <= m+f && m+f < 65 {
			fmt.Println("C")
		} else if 30 <= m+f && m+f < 50 {
			if 50 <= r {
				fmt.Println("C")
			} else {
				fmt.Println("D")
			}
		} else {
			fmt.Println("F")
		}
	}
}
