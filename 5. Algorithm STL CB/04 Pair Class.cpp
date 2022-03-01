#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, char> p;
    p.first = 10;
    p.second = 'a';

    pair<int, char>p2(p);
    cout << p2.first << " " << p2.second << endl;

    pair<int, string> p3 = make_pair(100, "audi");
    cout << p3.first << " " << p3.second << endl;

    pair < pair<int, int>, string> car;
    car.second = "audi";
    car.first.first = 10;
    car.first.second = 20;
    cout << car.first.first << " " << car.first.second << " " << car.second << endl;


    return 0;
}