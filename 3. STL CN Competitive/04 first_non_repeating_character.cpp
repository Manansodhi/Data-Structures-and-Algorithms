#include"bits/stdc++.h"
using namespace std;

char Non_Repeating_Character(string s){
    map<char, int> freq;
    for (int i = 0; i < s.length(); i++){
        char current_char = s[i];
        freq[current_char]++;
    }

    for (int i = 0; i < s.length(); i++){
        if (freq[s[i]] == 1){
            return s[i];
        }
    }
    return s[0];
}

int main(){
    string s = "aabb";
   cout << Non_Repeating_Character(s) << endl;
    return 0;
}