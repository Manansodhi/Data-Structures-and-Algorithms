#include<bits/stdc++.h>
using namespace std;

/*
Unordered Map -> Implementation of hash table, inser(),erase(),find() ==> O(1) on average. becoz some times
when rehashing take place then O(N) time will be taken

*/

unordered_map<string,int>UM;
UM.insert(make_pair("Mango", 100));

// we can change map with unordered_map in map.cpp file ONLY DIFFERENCE will be that output will NOT be 
// in SORTED ORDER 