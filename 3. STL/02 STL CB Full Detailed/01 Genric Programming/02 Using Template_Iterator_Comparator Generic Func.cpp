#include<bits/stdc++.h>
using namespace std;

/*
template -> freedom from data types
template+ iterator -> freedom from different type of container
template+ iterator+ comparator -> freedom from different types of operation operating on data (object like list of books, vector of Aadhar card no)
*/

class Book {
public:
    string name;
    int price;
    Book() {

    }
    Book(string name, int price) {
        this->name = name;
        this->price = price;
    }
};

template<class forwardIterator, class T, class compare>
forwardIterator search(forwardIterator start, forwardIterator end, T key, compare cmp) {
    while (start != end) {
        if (cmp(*start, key)) {
            return start;
        }
        start++;
    }
    return end;
}

class BookCompare {
public:
    //overloading "()" operator to compare the name of the book becoz we want to find the book price does ot matters
    bool operator()(Book a, Book b) {
        if (a.name == b.name) {
            return true;
        }
        return false;
    }
};

int main() {
    Book b1("C++", 100);
    Book b2("Java", 120);
    Book b3("Python", 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C++", 110);

    BookCompare cmp; // cmp object of comparator class passed in the search function to find the book with same name

    //or
    //auto it
    list<Book>::iterator it = search(l.begin(), l.end(), booktofind, cmp);

    if (it != l.end()) {
        cout << "book found in libary" << endl;
    }
    else {
        cout << "Book not found" << endl;
    }

    return 0;
}
