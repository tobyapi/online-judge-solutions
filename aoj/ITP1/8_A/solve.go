package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _, _ := reader.ReadLine()
	for _, r := range string(s) {
		if unicode.IsLower(r) {
			fmt.Printf("%c", unicode.ToUpper(r))
		} else if unicode.IsUpper(r) {
			fmt.Printf("%c", unicode.ToLower(r))
		} else {
			fmt.Printf("%c", r)
		}
	}
	fmt.Println()
}
