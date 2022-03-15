#include<bits/stdc++.h>
using namespace std;

// TIME:- O(N^2)

int main() {
    int ans = 0, n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int minh = INT_MAX;
        for (int j = i; j < n; j++) {
            minh = min(a[j], minh);
            int len = j - i + 1;
            ans = max(ans, len * minh);
        }
    }
    cout << ans << endl;
    return 0;
}