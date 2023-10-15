class LinearInterpolation:
    def __init__(self, x_values, y_values):
        # Check if the number of x and y values match
        if len(x_values) != len(y_values):
            raise ValueError("The number of x and y values must be the same")
        self.x_values = x_values
        self.y_values = y_values

    def interpolate(self, x):
        # Check if x is out of the range of the given data
        if x < min(self.x_values) or x > max(self.x_values):
            raise ValueError("x is outside the range of the given data")

        # Perform linear interpolation
        for i in range(len(self.x_values) - 1):
            if x >= self.x_values[i] and x <= self.x_values[i + 1]:
                x0, x1 = self.x_values[i], self.x_values[i + 1]
                y0, y1 = self.y_values[i], self.y_values[i + 1]
                slope = (y1 - y0) / (x1 - x0)
                # Calculate the interpolated value using the linear equation
                return y0 + slope * (x - x0)

        return None

# Example of using LinearInterpolation
x_values = [0, 1, 2, 3, 4]
y_values = [0, 1, 4, 9, 16]

interpolator = LinearInterpolation(x_values, y_values)
x = 2.5
result = interpolator.interpolate(x)
if result is not None:
    print(f"Interpolation at x={x} is {result}")
else:
    print("x is outside the range of the given data")
