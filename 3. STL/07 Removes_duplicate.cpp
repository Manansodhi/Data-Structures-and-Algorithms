#include<bits/stdc++.h>
using namespace std;

void Remove_Duplicate(vector<int> arr){
    set<int> s;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++){
        if (s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }
    vector<int> :: iterator it;
 for (int i = result.begin(); i != result.end(); i++){
        cout << *it <<" ";
    }
    cout << endl;
}

// OR

vector<int> Remove_Duplicate(vector<int> arr){
    vector<int> result;
    sort(arr, arr+n);
    result.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] != arr[i-1]){
            result.push_back(arr[i]);
        } 
    }
    return result;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >>  n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> v;
    for (int i = 0; i < n; i++){
        v.push_back(arr[i]);
    }

    Remove_Duplicate(v);
    return 0;
}