#include<bits/stdc++.h>
using namespace std;

// TIME:- O(N) becoz for every bar push and pop will occur only once

int get_max_area(vector<int> a) {
    int n = a.size(), ans = 0, i = 0;

    stack<int> st;
    a.push_back(0);  // If any value is left at the end of stack so we don't have to handle that

    while ( i < n) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int h = a[st.top()];
            st.pop();
            /*when poping we are finding the area of region considering that current bar has min height bar
            if stack is NOT empty ==> area=h(height of min bar) * (r (rightmost bar less than height) - l (leftmost bar less
            than height) - 1)
            if stack is empty ==> area=(h (height of min bar) * i (right most index))
            */
            if (st.empty()) {
                ans = max(ans, h * i);
            }
            else {
                int width = i - st.top() - 1;
                ans = max(ans, h * width);
            }

        }
        /*push the ith index of bar in stack s if it is greater then top of stack(matlab ki agar koi badi bar arahi toh voh 
        acha h hmare liye toh usko stack m dal do). otherwise when all bars are of smaller heights then pop all the bars of 
        greater height(or agar smaller height ki bar ayi h toh sari badi bar ko pop kar do unka arae nikal ke)*/  
        st.push(i);
        i++;
    }
    return ans;
}

int main() {
    vector<int> a = {6, 2, 5, 4, 5, 1, 6};
    cout << get_max_area(a) << endl;


}