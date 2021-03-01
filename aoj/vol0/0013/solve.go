package main

import (
	"errors"
	"fmt"
)

type T int

type Stack []T

func NewStack() *Stack {
	s := new(Stack)
	return s
}

func (s *Stack) Size() int {
	return len(*s)
}

func (s *Stack) Empty() bool {
	return s.Size() == 0
}

func (s *Stack) Push(v T) {
	*s = append(*s, v)
}

func (s *Stack) Pop() (T, error) {
	if s.Empty() {
		return 0, errors.New("")
	}

	v := (*s)[len(*s)-1]
	*s = (*s)[:len(*s)-1]
	return v, nil
}

func main() {
	stack := NewStack()
	for {
		var n T
		in, _ := fmt.Scan(&n)
		if in != 1 {
			return
		}

		if n == 0 {
			v, _ := stack.Pop()
			fmt.Println(v)
		} else {
			stack.Push(n)
		}
	}
}
