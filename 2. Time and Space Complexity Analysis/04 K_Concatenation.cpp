#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// INPUT
// N K
// 2 3
// ARRAY ELEMENTS
// 1 2
// OUTPUT 1
// 9
// INPUT 2
// 3 2
// 1 -2 1
// OUTPUT 2
// 2
// TIME :- O(N)
// SPACE :- O(1)

ll largest_sum_subarray(int *arr, int n) {
    ll curr_max_sum = 0;
    ll best_sum_so_far = 0;

    for (int i = 0; i < n; i++) {
        curr_max_sum += arr[i];
        if (curr_max_sum > best_sum_so_far) {
            best_sum_so_far = curr_max_sum;
        }
        if (curr_max_sum < 0) {
            curr_max_sum = 0;
        }
    }
    return best_sum_so_far;
}

ll k_con(int *arr, int n, int k) {
    ll kadnes_sum = largest_sum_subarray(arr, n);
    if (k == 1) {
        return kadnes_sum;
    }

    ll curr_prefix_sum = 0, curr_suffix_sum = 0;
    ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;

    for (int i = 0; i < n; i++) {
        curr_prefix_sum += arr[i];
        if (curr_prefix_sum > max_prefix_sum) {
            max_prefix_sum = curr_prefix_sum;
        }
        // or
        // max_prefix_sum = max(curr_prefix_sum, max_prefix_sum);
    }

    ll total_sum = curr_prefix_sum;

    for (int i = n - 1; i >= 0; i--) {
        curr_suffix_sum += arr[i];
        max_suffix_sum = max(max_suffix_sum, curr_suffix_sum);
    }

    ll ans ;

    if (total_sum < 0) {
        ans = max(max_prefix_sum + max_suffix_sum, kadnes_sum);
    }
    else {
        ans = max(max_prefix_sum + max_suffix_sum + (total_sum * (k - 2)), kadnes_sum);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int  t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr [n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << k_con(arr, n, k) << endl;
    }

    return 0;

}