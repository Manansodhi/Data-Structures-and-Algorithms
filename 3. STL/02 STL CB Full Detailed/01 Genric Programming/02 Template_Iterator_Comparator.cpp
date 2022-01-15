#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    string name;
    int price;
    Book(){

    }
    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

template<class forwardIterator, class T, class compare>
forwardIterator search(forwardIterator start, forwardIterator end, T key, compare cmp){
    while (start != end){
        if(cmp(*start, key)){
            return start;
        }
        start++;
    }
    return end;
}

class BookCompare{
    public:
    bool operator()(Book a, Book b){
        if(a.name == b.name){
            return true;
        }
        return false;
    }
};

int main(){
    Book b1("C++", 100);
    Book b2("Java", 120);
    Book b3("Python", 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C", 110);

    BookCompare cmp;
    auto it = search(l.begin(), l.end(), booktofind, cmp);

    if (it != l.end()){
        cout << "book found in he libary" << endl;
    }
    else{
        cout << "Book not found" << endl; 
    }

    return 0;
}
