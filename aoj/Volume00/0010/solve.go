package main

import (
	"fmt"
	"math"
)

type Point struct {
	x float64
	y float64
}

func (p Point) Add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y}
}

func (p Point) Sub(q Point) Point {
	return Point{p.x - q.x, p.y - q.y}
}

func (p Point) Mul(i int32) Point {
	return Point{p.x * 2, p.y * 2}
}

func (p Point) Div(f float64) Point {
	return Point{p.x / f, p.y / f}
}

func (p Point) Norm() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point) Dist(q Point) float64 {
	return p.Sub(q).Norm()
}

func (p Point) Dot(q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p Point) Cross(q Point) float64 {
	return p.x*q.y - p.y*q.x
}

type Circle struct {
	p Point
	r float64
}

func circumscribedCircle(p Point, q Point, r Point) Circle {
	a := (q.Sub(p)).Mul(2)
	b := (r.Sub(p)).Mul(2)
	c := Point{p.Dot(p) - q.Dot(q), p.Dot(p) - r.Dot(r)}
	tmp := Point{a.y*c.y - b.y*c.x, b.x*c.x - a.x*c.y}
	center := tmp.Div(a.Cross(b))
	return Circle{center, p.Dist(center)}
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var p Point
		var q Point
		var r Point
		fmt.Scan(&p.x, &p.y, &q.x, &q.y, &r.x, &r.y)
		result := circumscribedCircle(p, q, r)
		fmt.Printf("%.3f %.3f %.3f\n", result.p.x, result.p.y, result.r)
	}
}
