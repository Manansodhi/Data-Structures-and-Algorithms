#include<bits/stdc++.h>
using namespace std;

int main() {

    char ch;
    cin >> ch;
    queue<char>q;
    int freq[27] = {0};

    while (ch != '.') {
        //reading stream of character untill "."
        q.push(ch);
        freq[ch - 'a']++;
        //storing frequency of each alphabet at its same position in english language like c-a=2 so freq of c will be
        //stored at 2nd index by incrementing each time

        //query -> Now removing all chars from front of queue which have frequency greater than 1

        while (!q.empty()) {
            int idx = q.front() - 'a';
            //finding index of alphabet by subtracting from 'a' to check the freq of that character
            if (freq[idx] > 1) {
                q.pop();
            }
            else {
                cout << q.front() << endl;
                break;
            }
        }
        if (q.empty()) {
            cout << "-1" << endl;
        }
        cin >> ch; //reading next character
    }//end of while loop
    return 0;
}