#include<bits/stdc++.h>
using namespace std;

void solve(int *arr, int target, int n)
{
    int start = 0;
    int end = 0;
    int sum = arr[0];
    while (start < n && end < n) {
        if ( sum < target) {
            end++;
            sum += arr[end];
        }
        else if (sum > target) {
            sum -= arr[end];
            start++;
        }
        else {
            cout << "true" << endl;
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            return;
        }
    }
    cout << "false " << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    int * arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    solve(arr, target, n);
    return 0;

}