#include<bits/stdc++.h>
using namespace std;

int largest_sum_subarray(int *arr, int n) {
    int curr_max_sum = 0;
    int best_sum_so_far = 0;
    int  start = 0, end = 0, s = 0;

    for (int i = 0; i < n; i++) {
        curr_max_sum += arr[i];
        if (curr_max_sum > best_sum_so_far) {
            best_sum_so_far = curr_max_sum;
            start = s;
            end = i;
        }
        if (curr_max_sum < 0) {
            curr_max_sum = 0;
            s = i + 1;
        }
    }
     cout << "starting index " << start << endl;
     cout << "Ending Index " << end << endl;
    return best_sum_so_far;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << largest_sum_subarray(arr, n) << endl;
}