package main

import "fmt"

func main() {
	var a [5]int
	fmt.Println("hasil:", a)

	a[4] = 100
	a[3] = 200
	fmt.Println("perubahan:", a)
	fmt.Println("ambil nilai index ke-4:", a[4])
	fmt.Println("pangjang:", len(a))

	b := [5]int{1, 2, 3, 4, 5}
	fmt.Println("init langsung:", b)

	var duaDimensi [2][3]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			duaDimensi[i][j] = i + j
		}
	}

	fmt.Println("arrays multidimensi:", duaDimensi)

	//declare and initialize
	c := [3]int{
		1,
		2,
		3,
	}

	c[0] = 100
	fmt.Println("langsung declare:", c)
}
