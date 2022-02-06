#include"bits/stdc++.h"
using namespace std;

template<class forwardIterator, class T>

forwardIterator search(forwardIterator start, forwardIterator end, T key){
    while ( start != end){
        if (*start == key){
            return start;
        }
        start++;
    }
    return end;
}

int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);
    l.push_back(10);

    auto it = search(l.begin(), l.end(), 5);
    if (it == l.end()){
        cout << "Element not found" << endl;
    }
     else {
         cout << *it << endl;
     }

     return 0;
}