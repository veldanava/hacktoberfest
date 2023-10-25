const date = new Date().toISOString()

const formatDate = date => {
  return new Date(date).toLocaleDateString("id-ID", { weekday: "long", year: "numeric", month: "long", day: "numeric" })
}

// Formatting date to day, dd month yyyy (Rabu, 25 Oktober 2023)
console.log(formatDate(date))
