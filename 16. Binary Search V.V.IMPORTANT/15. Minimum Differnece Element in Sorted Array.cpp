//15. Minimum Differnece Element in Sorted Array
int minDiffElement(int arr[], int key, int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			return arr[mid];
		}
		else if (arr[mid] >= key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	int left_neighnour = arr[end], right_neighbour = arr[start];
	if (abs(left_neighnour - key) > abs(right_neighbour - key)) {
		return right_neighbour;
	}
	return left_neighnour;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1,3,8,10,11,15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ele=12;
	cout<<minDiffElement(arr,ele,n)<<endl;

return 0;
}