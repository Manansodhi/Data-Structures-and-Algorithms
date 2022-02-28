#include<bits/stdc++.h>
using namespace std;

//In template class we have onle class of forwardinterartor which will specify the type of container and another class of type T which will specify the data type of variable
template<class forwardIterator, class T>

//search function going to return forward interator
forwardIterator search(forwardIterator start, forwardIterator end, T key) {
    while ( start != end) {
        if (*start == key) {
            return start;
        }
        start++;
    }
    return end;
}

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(5);
    l.push_back(3);
    l.push_back(10);

    //parameter of search function are l.begin()-> it is iterator has data type of list<int> :: iterator and our forwarditerator will have this data type
    auto it = search(l.begin(), l.end(), 5);
    if (it == l.end()) {
        cout << "Element not found" << endl;
    }
    else {
        cout << *it << endl;
    }

    return 0;
}