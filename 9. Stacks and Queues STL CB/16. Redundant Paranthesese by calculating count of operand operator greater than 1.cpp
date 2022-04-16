#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool ans = false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
            st.push(s[i]);
        }
        else if ( s[i] == '(') {
            st.push(s[i]); //pushing all Operand and Operator in stack except clasing bracket"("
        }
        else if (s[i] == ')') {
            if (st.top() == '(') {
                ans = true;
                // ye uske liye jub '(' and ')' eske bich me kuch na ho toh matlab redundant h tu ye true kar deka ans ko
            }
            while (st.top() == '+' || st.top() == '/' || st.top() == '*' || st.top() == '-') {
                st.pop();
            }
        }
        st.pop();//ye sirf '(' esko pop karne ki liye h agar multiple opening paranthessis ho toh
    }

    cout << ans << endl;

    return 0;
}
