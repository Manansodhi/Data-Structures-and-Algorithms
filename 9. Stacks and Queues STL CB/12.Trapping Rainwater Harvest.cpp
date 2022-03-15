#include<bits/stdc++.h>
using namespace std;


//TIME :- O(N)
int Trapped_rainwater(vector<int> a){
    int n = a.size(), ans = 0, i = 0;

    stack<int>st;

    while (i < n){
        while (!st.empty() && a[st.top()] < a[i]){
            int curr = st.top(); // is calculated so tha while calculating height of water contained we have to subtract the height of current block
            st.pop(); 


            if(st.empty()){
                break;
            }
            int len = i - st.top() - 1; // this will always return 1 as len of each block is 1
            ans += (min(a[st.top()], a[i]) - a[curr]) * len;
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> a = {0,2,1,3,0,1,2,1,2,1};
    cout << Trapped_rainwater(a) << endl;

    return 0;
}