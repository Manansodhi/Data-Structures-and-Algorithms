#include<bits/stdc++.h>
using namespace std;

// TIME:- O(N^2)

int get_max_area(vector<int> a) {
    int n = a.size(), ans = 0, i = 0;

    stack<int> st;
    a.push_back(0);  // If any value is left at the end of stack so we don't have to handle that

    while ( i < n) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int h = a[st.top()];
            st.pop();
            if (st.empty()) {
                ans = max(ans, h * i);
            }
            else {
                int width = i - st.top() - 1;
                ans = max(ans, h * width);
            }

        }
        st.push(i);
        i++;
    }
    return ans;
}

int main() {
    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    cout << get_max_area(a) << endl;


}