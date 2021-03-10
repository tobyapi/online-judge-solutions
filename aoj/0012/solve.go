package main

import (
	"fmt"
	"math"
)

type Point struct {
	x float64
	y float64
}

func (p Point) Sub(q Point) Point {
	return Point{p.x - q.x, p.y - q.y}
}

func (p Point) Norm() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point) Dot(q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p Point) Cross(q Point) float64 {
	return p.x*q.y - p.y*q.x
}

type Polygon struct {
	v []Point
}

func NewPolygon(points ...Point) *Polygon {
	return &Polygon{points}
}

func (p *Polygon) Curr(i int) Point {
	return p.v[i%len(p.v)]
}

func (p *Polygon) Next(i int) Point {
	return p.v[(i+1)%len(p.v)]
}

func (p *Polygon) Size() int {
	return len(p.v)
}

func (pol *Polygon) Contains(p Point) int {
	in := false
	for i := 0; i < pol.Size(); i++ {
		a := pol.Curr(i).Sub(p)
		b := pol.Next(i).Sub(p)
		if b.y < a.y {
			a, b = b, a
		}
		if a.y <= 0 && 0 < b.y && a.Cross(b) < 0 {
			in = !in
		}
		if a.Cross(b) == 0 && a.Dot(b) <= 0 {
			return 2
		}
	}
	if in {
		return 1
	}
	return 0
}

func main() {
	for {
		var a Point
		var b Point
		var c Point
		var p Point
		n, _ := fmt.Scan(&a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &p.x, &p.y)

		if n != 8 {
			return
		}

		result := NewPolygon(a, b, c).Contains(p)
		if result == 1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
