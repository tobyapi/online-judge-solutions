package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func is_alpha(r rune) bool {
	return unicode.IsUpper(r) || unicode.IsLower(r)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	m := make(map[rune]int)
	for {
		s, _, err := reader.ReadLine()
		if err != nil {
			break
		}
		for _, r := range string(s) {
			if is_alpha(r) {
				m[unicode.ToLower(r)] += 1
			}
		}
	}

	for i := 0; i < 26; i++ {
		r := rune('a' + i)
		fmt.Printf("%c : %d\n", r, m[r])
	}
}
