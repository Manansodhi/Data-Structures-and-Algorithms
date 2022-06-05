
// GOOGLE Allocate Minimum Number Of Pages

int MaxInArray(int arr[], int n) {
  int maxEle = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxEle = max(maxEle, arr[i]);
  }
  return maxEle;
}

int SumOfElementOfArray(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum + arr[i];
  }
  return sum;
}


bool isValid(int arr[], int n, int k, int maxNumberofPages) {
  int student = 1, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum > maxNumberofPages) {
      student++; //creating new student and distrubing pages to them for reading becoz it has crossed the max limit of student to read
      sum = arr[i];
    }
    if (student > k)
      return false;
  }
  return true;
}

int AllocateMinNumberofPages(int arr[], int n, int k) {
  if (n < k)
    return -1;
  int start, end;
  int result = -1;
  //set start as max in arr (LIKE THIS ALSO)
  //int start=*max_element(arr, arr + n);
  start = MaxInArray(arr, n);
  end = SumOfElementOfArray(arr, n);
  while (start <= end) {
    int mid = start + (end - start) / 2;
    // check if mid is maximum pages a student can read
    if (isValid(arr, n, k, mid)) {
      // if true then set result as mid and check if there exists a lower value(pages)
      result = mid;
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
  }
  return result;

}


int main() {
  int arr[] = {10, 20, 30, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int students = 2;
  cout << "Minimum pages each student has to read:" << AllocateMinNumberofPages(arr, n, students);
  return 0;
}