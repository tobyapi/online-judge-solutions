package main

import "fmt"

func main() {
	var h, w int
	for {
		n, _ := fmt.Scanf("%d %d", &h, &w)
		if n == 0 {
			break
		}

		for i := 0; i < h; i++ {
			for j := 0; j < w; j++ {
				if 0 < i && i < h-1 && 0 < j && j < w-1 {
					fmt.Print(".")
				} else {
					fmt.Print("#")
				}
			}
			fmt.Println()
		}
		fmt.Println()
	}
}
