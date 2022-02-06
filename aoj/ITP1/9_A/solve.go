package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	b, _, _ := reader.ReadLine()
	w := string(b)
	count := 0
	for {
		bytes, _, _ := reader.ReadLine()
		s := string(bytes)

		if s == "END_OF_TEXT" {
			break
		}

		words := strings.Split(s, " ")
		for _, word := range words {
			if strings.ToLower(word) == w {
				count++
			}
		}
	}
	fmt.Println(count)
}
