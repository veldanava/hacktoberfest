class Solution{
public:	
	// Function returns the second
	// largest elements
int print2largest(int arr[], int n) {
	// code here
	int max = -1000000000, max2 = -1000000000;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) { max = arr[i]; }
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > max2 and arr[i] < max) { max2 = arr[i]; }
	}
	if (max2 == -1000000000) { return -1; }
	return max2;
}
};
