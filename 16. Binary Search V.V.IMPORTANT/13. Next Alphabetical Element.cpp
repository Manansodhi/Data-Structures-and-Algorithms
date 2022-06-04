//13. Next Alphabetical Element

char nextGreatestLetter(vector<char>& letters, char target) {
	int n = letters.size();
	int l = 0, h = n - 1, m;
	char ans = letters[0];
	while (l <= h)
	{
		m = l + (h - l) / 2;
		int val = letters[m] - 'a';
		if (val > target - 'a')
		{
			ans = letters[m];
			h = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

int nextAlphabeticalElement(char arr[], int n, char target) {
	if (target == arr[n - 1])
		return 0;
	if (target > arr[n - 1])
		return -1;
	int start = 0, end = n - 1, res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			start = mid + 1;
		}
		if (arr[mid] > target) {
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return res;
}
char nextChar(char arr[], int n, char key) {
	int start = 0, end = n - 1, mid;
	char res = '0';

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] > key) {
			res = arr[mid];
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return res;
}

int main()
{
	char arr[100], ch;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> ch;

	if (nextalphabet(arr, n, ch) == -1)
		cout << "THE NEXT ALPHABET COULD NOT BE FOUND!" << "\n";
	else
		cout << arr[nextalphabet(arr, n, ch)];
	return 0;
}
