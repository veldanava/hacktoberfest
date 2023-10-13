package main

func main() {
	type noKTP string
	type married bool

	var ktpRizal noKTP = "123456789"
	var marriedStatus married = true

	println(ktpRizal)
	println(marriedStatus)

}
