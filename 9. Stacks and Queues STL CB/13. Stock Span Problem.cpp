#include<bits/stdc++.h>
using namespace std;

//TIME :- O(N)

vector<int> StockSpan(vector<int> prices) {
    vector<int> ans;
    stack<pair<int, int> >st;
    for (auto price : prices) {
        int days = 1;
        while (!st.empty() and st.top().first < price) {
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, days));
        ans.push_back(days);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    vector<int> result = StockSpan(a);
    for (auto i : result) {
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}